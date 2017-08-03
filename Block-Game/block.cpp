//
//  block.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/22.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "block.hpp"
#include <string>
#include <GLUT/GLUT.h>
#include <math.h>

Block::Block(){
    GameObject("block");
}

Block::Block(float posX, float posY){
    positionX = posX + (scaleX / 2) + interval;
    positionY = posY * scaleY + interval;
    GameObject("block");
}

void Block:: Drow(){
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

float Block::GetScaleX(){
    return this->scaleX;
}

float Block::GetScaleY(){
    return this->scaleY;
}

void Block::Collision(Ball* ball){
    
    if(ball->positionX + ball->GetRadius() < this->positionX + (scaleX / 2) &&
       ball->positionX - ball->GetRadius() > this->positionX - (scaleX / 2) &&
       abs(this->positionY + (this->GetScaleY() / 2) - ball->positionY) < ball->GetRadius()
       ){
        ball->velocity->y *= -1;
        this->isHit = true;
    }
    
}

