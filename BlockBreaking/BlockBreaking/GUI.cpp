#include "GUI.h"



GUI::GUI()
{
}


GUI::~GUI()
{
}

/*
* 文字列描画
* @param[in] str 文字列
* @param[in] w,h ウィンドウサイズ
* @param[in] x0,y0 文字列の一
*/
void GUI::DrawString(std::string str, int w, int h, int x0, int y0) 
{
	glDisable(GL_LIGHTING);
	//平行投影にする
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	//画面上にテキスト描画
	glRasterPos2f(x0, y0);
	int size = (int)str.size();
	for (int i = 0; i < size; ++i)
	{
		char ic = str[i];
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ic);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
