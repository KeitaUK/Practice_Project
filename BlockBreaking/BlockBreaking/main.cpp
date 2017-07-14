#include <stdio.h>
#include <gl/freeglut.h>

#include "Ball.h"
#include "Block.h"

#define WIDTH 500
#define HEIGHT 500
#define BLOCK_HEIGHT_NUM 4
#define BLOCK_WIDTH_NUM 6

Ball ball(0.1,-0.2 ,-0.4 ,1.0, 0, 0);
Block blocks[BLOCK_HEIGHT_NUM][BLOCK_WIDTH_NUM];


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	ball.draw();

	for (int y = 0; y < BLOCK_HEIGHT_NUM; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH_NUM; x++)
		{
			blocks[y][x].draw();
		}
	}

	glFlush();
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
		}
	}
	

}

int main(int argc, char *argv[])
{
	init();
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(display);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutReshapeFunc(resize);
	glutTimerFunc(50,timer,0);

	glutMainLoop();

	return 0;

}