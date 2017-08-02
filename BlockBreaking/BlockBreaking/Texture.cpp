#include "Texture.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glpng.h>
#include "Constants.h"
#include <iostream>
using namespace std;


Texture::Texture()
{
	vec.x = Constants::WIDTH/2;
	vec.y = Constants::HEIGHT/2;
	scale.x = 0;
	scale.y = 0;

}

Texture::Texture(float posX, float posY)
{
	vec.x = posX;
	vec.y = posY;
	scale.x = 0;
	scale.y = 0;
}


Texture::~Texture()
{
}

void Texture::load(const char* fileName)
{
	texture = pngBind(fileName, PNG_NOMIPMAP, PNG_ALPHA, &info, GL_CLAMP, GL_NEAREST, GL_NEAREST);
	scale.x = info.Width;
	scale.y = info.Height;
}


void Texture::draw()
{
	GLfloat vtx[] =
	{
		vec.x - scale.x/2 ,vec.y - scale.y/2,	//左上
		vec.x + scale.x/2 ,vec.y - scale.y/2,	//右上
		vec.x + scale.x/2 ,vec.y + scale.y/2,	//右下
		vec.x - scale.x/2 ,vec.y + scale.y/2,	//左下
	};
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	//Step5. テクスチャの領域指定
	static const GLfloat texuv[] =
	{
		0.0f,0.0f,
		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texuv);

	//Step6 テクスチャの画像指定
	glBindTexture(GL_TEXTURE_2D, texture);

	//step7 テクスチャの描画
	glEnable(GL_TEXTURE_2D);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);

}

void Texture::draw(float posX, float posY)
{
	vec.x = posX;
	vec.y = posY;
	draw();
}

void Texture::draw(float posX,float posY,float width,float height)
{
	scale.x = width;
	scale.y = height;
	draw(posX,posY);
}