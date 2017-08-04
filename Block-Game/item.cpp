//
//  item.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/03.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "item.hpp"
#include <GLUT/GLUT.h>

Item::Item(){
    GameObject("item");
    positionX = 0;
    positionY = 0;
}

Item::Item(float posX,float posY){
    
    GameObject("item");
    positionX = posX;
    positionY = posY;
    is_get = true;
}

void Item::Draw(){
    glBegin(GL_POLYGON);
    glVertex2f(positionX, positionY + scaleY/2);
    glVertex2f(positionX + scaleX /2, positionY);
    glVertex2f(positionX, positionY - scaleY /2);
    glVertex2f(positionX - scaleX/2, positionY);
    glVertex2f(positionX, positionY + scaleY/2);
    
    glEnd();
}
