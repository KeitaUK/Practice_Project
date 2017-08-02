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
Ball::Ball(float radius, float x, float y, Color& col)
{
	r = radius;
	posX = x;
	posY = y;
	color.r = col.r;
	color.g = col.g;
	color.b = col.b;
	
	moveX = moveSize;
	if (rand() % 2 == 0)
	{
		moveX = -moveSize;
	}

	moveY = -moveSize;
}

Ball::~Ball()
{
}


void Ball::draw()
{

	if (isDeleted)
		return;
	texture.vec.x = posX;
	texture.vec.y = posY;
	texture.draw();
	
}
/*
int i, n = PART;
double rate;
double x, y = 0.5;

//glColor3f(color.r, color.g, color.b);
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
*/
void Ball::draw(float posX, float posY)
{
	if (isDeleted)
		return;
	
	texture.draw(posX,posY);
}

void Ball::moveBall(ScoreManager& scoreMgr)
{
	if (isDeleted)
		return;

	posX += moveX;
	posY += moveY;

	if (posX >= Constants::WIDTH - r ) moveX = -moveSize;
	else if (posX <= 0 + r ) moveX = moveSize;
	
	//âÊñ â∫Ç…êGÇÍÇΩÇ∆Ç´ÇÃèàóù
	if (posY >= Constants::HEIGHT - r)
	{
		isDeleted = true;
		scoreMgr.decreaseBallNum();
	}
	else if (posY <= 0 + r ) moveY = moveSize;
}

void Ball::loadImage()
{
	texture.load("Images/ball.png");
	texture.vec.x = posX;
	texture.vec.y = posY;
	texture.scale.x = r*2;
	texture.scale.y = r*2;
}