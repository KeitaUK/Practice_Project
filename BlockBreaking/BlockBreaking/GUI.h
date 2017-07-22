#pragma once
#include <string>
#include <gl/freeglut.h>
class GUI
{
public:
	GUI();
	~GUI();
	static void DrawString(std::string str, int w, int h, int x0, int y0);
};

