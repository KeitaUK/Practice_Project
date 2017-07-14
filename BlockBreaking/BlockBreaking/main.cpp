#include <stdio.h>
#include <gl/freeglut.h>

#include "Ball.h"
#include "Block.h"
#include "Bar.h"

#define WIDTH 500
#define HEIGHT 500
#define BLOCK_HEIGHT_NUM 4
#define BLOCK_WIDTH_NUM 6

Ball ball(0.05,-0.2 ,-0.4 ,0.945, 0.537, 0);
Block blocks[BLOCK_HEIGHT_NUM][BLOCK_WIDTH_NUM];
Bar bar;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 0.0);

	ball.draw();
	bar.draw();

	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			blocks[y][x].draw();
		}
	}

	glutSwapBuffers();
}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		bar.move(0.1);
		break;
	case GLUT_KEY_LEFT:
		bar.move(-0.1);
		break;
	}
	glutPostRedisplay();
}

void timer(int value)
{
	ball.moveBall();
	

	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			blocks[y][x].collisionWithBall(ball);
		}
	}

	bar.collisionWithBall(ball);
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}


void resize(int w,int h)
{
	glViewport(0,0,w,h);
}

void init()
{
	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			blocks[y][x].posX = (double)x / 7 * 2 - 0.7;
			blocks[y][x].posY = -(double)y / 9 + 0.9;
			blocks[y][x].color.r = 1.0 * x/BLOCK_WIDTH_NUM;
			blocks[y][x].color.g = 1.0 - 1.0 * y/BLOCK_HEIGHT_NUM;
			blocks[y][x].color.b = (x/BLOCK_WIDTH_NUM + y/ BLOCK_HEIGHT_NUM) / 2;

		}
	}
	

}

int main(int argc, char *argv[])
{
	init();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(display);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutReshapeFunc(resize);
	glutTimerFunc(50,timer,0);
	glutSpecialFunc(keyboard);

	glutMainLoop();

	return 0;

}