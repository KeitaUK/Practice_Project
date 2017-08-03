//
//  Gui.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/02.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "Gui.hpp"
#include <GLUT/GLUT.h>

GUI::GUI(){
    return;
}

void GUI::DrawString(std::string str, int w, int h, int x0, int y0){
    
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
