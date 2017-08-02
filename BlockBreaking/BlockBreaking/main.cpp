#include <stdio.h>
#include <gl/freeglut.h>
#include <vector>
#include <iostream>
#include <string>

#include "Block.h"
#include "ObjectManager.h"
#include "GUI.h"
#include "ScoreManager.h"
#include "Constants.h"
#include "Texture.h"


Block blocks[Constants::BLOCK_NUM_HEIGHT][Constants::BLOCK_NUM_WIDTH];
ObjectManager objectManager;
ScoreManager scoreManager;
Texture background;

//メソッドの宣言
void init();
void display();
void idle(void);
void keyboard(unsigned char key, int x, int y);
void timer(int value);
void resize(int w, int h);
void mouse( int x, int y);

int main(int argc, char *argv[])
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(Constants::WIDTH, Constants::HEIGHT);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(display);
	init();
	glClearColor(0, 0, 0, 1.0);
	glutReshapeFunc(resize);
	glutTimerFunc(50,timer,0);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutPassiveMotionFunc(mouse);
	glutMainLoop();

	return 0;

}

void init()
{
	scoreManager.reset();
	objectManager.initialize();
	for (int y = 0; y < Constants::BLOCK_NUM_HEIGHT; y++)
	{
		for (int x = 0; x < Constants::BLOCK_NUM_WIDTH; x++)
		{
			float posX = (float)x * 60 + blocks[y][x].width / 2 + 10;
			float posY = (float)y * 20 + blocks[y][x].height / 2 + 10;
			float r = 1.0f * x / Constants::BLOCK_NUM_WIDTH;
			float g = 1.0f - 1.0f * y / Constants::BLOCK_NUM_HEIGHT;
			float b = ((float)(x / Constants::BLOCK_NUM_WIDTH) + (float)(y / Constants::BLOCK_NUM_HEIGHT)) / 2;
			Color col(r,g,b);
			blocks[y][x].init(posX,posY,col,false);
		}
	}
	objectManager.CreateBall(10,400, 400,scoreManager);
	background.load("Images/background.png");
	float ratio = (float)Constants::WIDTH / background.info.Width ;
	background.scale.x *= ratio;
	background.scale.y *= ratio;
	cout << background.scale.x;
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background.draw();
	if (scoreManager.isGameClear)
	{
		GUI::DrawString("Congratulations", Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH / 2 - 70, Constants::HEIGHT / 2);
		GUI::DrawString("Spase Key : Retry", Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH / 2 - 70, Constants::HEIGHT / 2 + 15);
		GUI::DrawString("Q key : exit", Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH / 2 - 70, Constants::HEIGHT / 2+ 15 + 15);
	}
	else if (scoreManager.isGameOver)
	{
		GUI::DrawString("Game Over.", Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH / 2 - 50, Constants::HEIGHT / 2);
		GUI::DrawString("Spase Key : Retry", Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH / 2 - 70, Constants::HEIGHT / 2 + 15);
		GUI::DrawString("Q key : exit", Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH / 2 - 70, Constants::HEIGHT / 2 + 15 + 15);
	}

	objectManager.drawBalls();
	objectManager.drawBars();

	for (int i = 0; i < objectManager.items.size(); i++)
	{
		objectManager.items[i].draw();
	}

	for (int y = 0; y < Constants::BLOCK_NUM_HEIGHT; y++)
	{
		for (int x = 0; x < Constants::BLOCK_NUM_WIDTH; x++)
		{
			blocks[y][x].draw();
		}
	}
	GUI::DrawString("SCORE = " + std::to_string(scoreManager.s_score), Constants::WIDTH, Constants::HEIGHT, Constants::WIDTH - 100, Constants::HEIGHT - 10);

	glutSwapBuffers();

}
void keyboard(unsigned char key, int x, int y)
{
	if (scoreManager.isGameClear || scoreManager.isGameOver)
	{

		switch (key)
		{
		case 'q':
		case 'Q':
		case '\033':
			exit(0);
			break;
		case ' ':
			init();
			break;
		}

		glutPostRedisplay();
	}
}

void mouse( int x, int y)
{
	if (scoreManager.isGameClear == 0 && scoreManager.isGameOver == 0)
	{
		objectManager.bar.posX = (float)x;
	}
}

void timer(int value)
{
	if (scoreManager.isGameClear == 0 && scoreManager.isGameOver == 0)
	{

		objectManager.moveBalls(scoreManager);

		//blockのあたり判定
		for (int y = 0; y < Constants::BLOCK_NUM_HEIGHT; y++)
		{
			for (int x = 0; x < Constants::BLOCK_NUM_WIDTH; x++)
			{
				for (int i = 0; i < objectManager.balls.size(); i++)
				{
					blocks[y][x].collisionWithBall(objectManager.balls[i], objectManager, scoreManager);
				}
			}
		}

		//barのあたり判定
		for (int i = 0; i < objectManager.balls.size(); i++)
			objectManager.bar.collisionWithBall(objectManager.balls[i]);

		//itemのあたり判定
		for (int i = 0; i < objectManager.items.size(); i++)
		{
			objectManager.items[i].move();
			objectManager.items[i].collisionWithBar(objectManager.bar, scoreManager, objectManager);
		}

		glutPostRedisplay();
	}
	glutTimerFunc(50, timer, 0);

}

void resize(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0,w,h,0);
	glOrtho(0.0, Constants::WIDTH, Constants::HEIGHT, 0.0, -1.0, 1.0);
}

void idle(void)
{
	glutPostRedisplay();
}