#include "Ball.h"
#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>

#define M_PI 3.14159265358979
#define PART 100

Ball::Ball()
{
	r = 0.5;
	color.r = 1.0;
	color.g = 1.0;
	color.b = 1.0;
	posX = 0;
	posY = 0;
	moveX = 0.1;
	moveY = 0.0;
}

Ball::Ball(double radius, float red, float gleen, float blue)
{
	r = radius;
	color.r = red;
	color.g = gleen;
	color.b = blue;
	posX = 0;
	posY = 0;
	moveX = 0.1;
	moveY = 0.0;
}

Ball::Ball(double radius,double x,double y, float red, float gleen, float blue)
{
	r = radius;
	posX = x;
	posY = y;
	color.r = red;
	color.g = gleen;
	color.b = blue;
	moveX = 0.1;
	moveY = -0.1;
}

Ball::~Ball()
{
}


void Ball::draw()
{
	int i, n = PART;
	double rate;
	double x, y = 0.5;

	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POLYGON);

	for (i = 0; i < n; i++)
	{
		rate = (double)i / n;
		x = r * cos(2.0 * M_PI * rate) + posX;
		y = r * sin(2.0 * M_PI * rate) + posY;
		glVertex3f(x, y, 0.0);
	}

	glEnd();
	glFlush();
}

void Ball::draw(double posX, double posY)
{
	int i, n = PART;
	double rate;
	double x, y = 0.5;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POLYGON);

	for (i = 0; i < n; i++)
	{
		rate = (double)i / n;
		x = r * cos(2.0 * M_PI * rate) + posX;
		y = r * sin(2.0 * M_PI * rate) + posY;
		glVertex3f(x,y,0.0);
	}

	glEnd();
	glFlush();
}

void Ball::moveBall()
{
	posX += moveX;
	posY += moveY;

	if (posX > 1 - r * 2) moveX = -0.1;
	else if (posX < -1 + r * 2) moveX = 0.1;
	
	if (posY > 1 - r * 2)moveY = -0.1;
	else if (posY < -1 + r * 2) moveY = 0.1;
}