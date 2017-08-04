//
//  player.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/21.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "player.hpp"

#include <GLUT/GLUT.h>


Player::Player(float posX,float posY){
    GameObject("player");
    positionX = posX;
    positionY = posY;
}

float Player::GetscaleX(){
    return this->scaleX;
}

float Player::GetscaleY(){
    return this->scaleY;
}

void Player::Draw(){
    
    glBegin(GL_POLYGON);
    glVertex2f(positionX, positionY);
    glVertex2f(positionX + scaleX /2, positionY);
    glVertex2f(positionX + scaleX / 2, positionY + scaleY /2);
    glVertex2f(positionX , positionY + scaleY /2);
    glVertex2f(positionX - scaleX/2, positionY + scaleY /2);
    glVertex2f(positionX - scaleX/2 , positionY);
    glVertex2f(positionX, positionY);
    
    glEnd();
}

void Player::MoveRight(){
    this->positionX += moveX;
    glutPostRedisplay();
}

void Player::MoveLeft(){
    this->positionX -= moveX;
    glutPostRedisplay();
}


