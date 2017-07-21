#include "Bar.h"
#include <GL/freeglut.h>


Bar::Bar()
{
	color.r = 0.0;
	color.g = 0.031;
	color.b = 0.235;
	posX = 250;
	posY = 450;
	width = 200;
	height = 10;
}


Bar::~Bar()
{
}

void Bar::draw()
{

	glColor4f(color.r, color.g, color.b, 0.0);

	glRectf(posX - width / 2, posY - height / 2, posX + width / 2, posY + height / 2);

}

void Bar::collisionWithBall(Ball& ball)
{

	//ボールが上側から触れたら反射
	if ((ball.posY <= posY) && ((ball.posY + ball.r ) >= (posY - (height /2))) && ((ball.posX - ball.r) <= (posX + (width / 2))) && ((ball.posX + ball.r)  >= (posX - (width / 2))))
	{
		ball.moveY = -ball.moveSize;
		ball.posY = posY - height / 2 - ball.r;
	}

	//ボールが下から触れたら反射
	if ((ball.posY >= posY) && ((ball.posY - ball.r) <= (posY + (height/2))) && ((ball.posX - ball.r)  <= (posX + (width / 2))) && ((ball.posX + ball.r ) >= (posX - (width / 2))))
	{
		ball.moveY = ball.moveSize;
		ball.posY = posY + height / 2 + ball.r;
	}
}

void Bar::move(float deltaX)
{

	posX += deltaX;
	if (posX + width / 2 >= Constants::WIDTH)
	{
		posX = Constants::WIDTH - width/2;
	}
	else if (posX - width / 2 <= 0)
	{
		posX = width/2;
	}
}
