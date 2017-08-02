#pragma once
#include <GL/freeglut.h>
#include <GL/glpng.h>
#include "Vec2.h"

class Texture
{
public:
	Texture();
	Texture(float posX, float posY);
	~Texture();
	Vec2 vec;
	Vec2 scale;
	char* data;
	void load(const char* fileName);
	GLuint texture;
	pngInfo info;
	void draw();
	void draw(float posX,float posY);
	void draw(float posX, float posY,float width,float height);
};

