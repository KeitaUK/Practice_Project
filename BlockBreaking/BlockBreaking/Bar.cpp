#include "Bar.h"
#include <GL/freeglut.h>


Bar::Bar()
{
	color.r = 0.0;
	color.g = 0.031;
	color.b = 0.235;
	posX = 0;
	posY = -0.7;
	width = 0.5;
	height = 0.07;
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
	

	//ボールが右側から触れたら反射
	if ((ball.posX > posX) && ((ball.posX - ball.r*2)<= (posX + (width / 2))) && ((ball.posY - ball.r ) <= (posY + (height / 2))) && ((ball.posY + ball.r)  >=( posY - (height / 2))))
	{
		ball.moveX = ball.moveSize;
	}

	//ボールが左側から触れたら反射
	if ((ball.posX < posX) && ((ball.posX + ball.r *2)>= (posX - (width / 2))) && ((ball.posY - ball.r) <= (posY +( height / 2))) && ((ball.posY + ball.r )>= (posY -( height / 2))))
	{
		ball.moveX = -ball.moveSize;

	}

	//ボールが下側から触れたら反射
	if ((ball.posY < posY) && ((ball.posY + ball.r * 2) >= (posY - (height / 2))) && ((ball.posX - ball.r) <= (posX + (width / 2))) && ((ball.posX + ball.r)  >= (posX - (width / 2))))
	{
		ball.moveY = -ball.moveSize;
	}

	//ボールが上から触れたら反射
	if ((ball.posY > posY) && ((ball.posY - ball.r*2) <= (posY + (height / 2))) && ((ball.posX - ball.r)  <= (posX + (width / 2))) && ((ball.posX + ball.r ) >= (posX - (width / 2))))
	{
		ball.moveY = ball.moveSize;
	}
}

void Bar::move(float deltaX)
{

	posX += deltaX;
	if (posX + width / 2 >= 1)
	{
		posX = 1 - width/2;
	}
	else if (posX - width / 2 <= -1)
	{
		posX = -1 + width/2;
	}
}
