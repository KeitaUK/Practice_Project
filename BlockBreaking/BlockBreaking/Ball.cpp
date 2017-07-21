#include "Ball.h"
#include <stdio.h>
#include <GL/freeglut.h>
#include <math.h>

#define M_PI 3.14159265358979
#define PART 100

Ball::Ball()
{

}

/*
* @param[in] radius îºåa
* @param[in] x xç¿ïW
* @param[in] y yç¿ïW
* @param[in] red colorR
* @param[in] gleen colorG
* @param[in] blue colorB
*/
Ball::Ball(float radius, float x, float y, float red, float gleen, float blue)
{
	r = radius;
	posX = x;
	posY = y;
	color.r = red;
	color.g = gleen;
	color.b = blue;
	moveX = moveSize;
	moveY = -moveSize;
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
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xACF3);
	for (i = 0; i < n; i++)
	{
		rate = (double)i / n;
		x = r * cos(2.0 * M_PI * rate) + posX;
		y = r * sin(2.0 * M_PI * rate) + posY;
		glVertex3f(x, y, 0.0);
	}

	glEnd();

}

void Ball::draw(float posX, float posY)
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

	if (posX >= Constants::WIDTH - r ) moveX = -moveSize;
	else if (posX <= 0 + r ) moveX = moveSize;
	
	if (posY >= Constants::HEIGHT - r )moveY = -moveSize;
	else if (posY <= 0 + r ) moveY = moveSize;
}