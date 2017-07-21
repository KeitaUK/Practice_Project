#include "GUI.h"



GUI::GUI()
{
}


GUI::~GUI()
{
}

/*
* ������`��
* @param[in] str ������
* @param[in] w,h �E�B���h�E�T�C�Y
* @param[in] x0,y0 ������̈�
*/
void GUI::DrawString(std::string str, int w, int h, int x0, int y0) 
{
	glDisable(GL_LIGHTING);
	//���s���e�ɂ���
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	//��ʏ�Ƀe�L�X�g�`��
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
