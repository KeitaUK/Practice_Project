#include <stdio.h>
#include <gl/freeglut.h>
#include <vector>
#include <iostream>
#include <string>

#include "Ball.h"
#include "Block.h"
#include "Bar.h"
#include "Item.h"
#include "ObjectManager.h"
#include "GUI.h"
#include "ScoreManager.h"
#include "Constants.h"

#define BLOCK_HEIGHT_NUM 6
#define BLOCK_WIDTH_NUM 8

Block blocks[BLOCK_HEIGHT_NUM][BLOCK_WIDTH_NUM];
Bar bar;
ObjectManager objectManager;
ScoreManager scoreManager;

//メソッドの宣言
void init();
void display();
void keyboard(int key, int x, int y);
void timer(int value);
void resize(int w, int h);

int main(int argc, char *argv[])
{
	init();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(Constants::WIDTH, Constants::HEIGHT);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(display);
	
	glClearColor(0, 0, 0, 1.0);
	glutReshapeFunc(resize);
	glutTimerFunc(50,timer,0);
	glutSpecialFunc(keyboard);

	glutMainLoop();

	return 0;

}

void init()
{
	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			blocks[y][x].posX = (float)x * 60 + blocks[y][x].width /2 + 10;
			blocks[y][x].posY = (float)y * 20 + blocks[y][x].height /2 + 10;
			blocks[y][x].color.r = 1.0f * x/BLOCK_WIDTH_NUM;
			blocks[y][x].color.g = 1.0f - 1.0f * y/BLOCK_HEIGHT_NUM;
			blocks[y][x].color.b = ((float)( x / BLOCK_WIDTH_NUM ) + (float)( y / BLOCK_HEIGHT_NUM )) / 2;

		}
	}
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0.0);

	objectManager.drawBalls();
	bar.draw();

	for (int i = 0; i <objectManager.items.size(); i++)
	{
		objectManager.items[i].draw();
	}

	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			blocks[y][x].draw();
		}
	}
	GUI::DrawString("SCORE = " + std::to_string(scoreManager.s_score),Constants::WIDTH,Constants::HEIGHT,Constants::WIDTH - 100,Constants::HEIGHT - 10);
	glutSwapBuffers();
}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		bar.move(10);
		break;
	case GLUT_KEY_LEFT:
		bar.move(-10);
		break;
	}
	glutPostRedisplay();
}

void timer(int value)
{
	objectManager.moveBalls();
	
	//blockのあたり判定
	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			for(int i = 0;i< objectManager.balls.size();i++)
			{
				blocks[y][x].collisionWithBall(objectManager.balls[i], objectManager, scoreManager);
			}
		}
	}

	//barのあたり判定
	for (int i = 0; i< objectManager.balls.size(); i++)
		bar.collisionWithBall(objectManager.balls[i]);
	
	//itemのあたり判定
	for (int i = 0; i < objectManager.items.size(); i++)
	{
		objectManager.items[i].move();
		objectManager.items[i].collisionWithBar(bar, scoreManager,objectManager);
	}
	
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}


void resize(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,h,0);
}

