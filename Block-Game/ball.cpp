//
//  ball.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/21.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "ball.hpp"
#include "Constants.h"
#include <iostream>
#include <GLUT/GLUT.h>
#include <math.h>
#include <random>
#include <cmath>
#include "GameManager.h"

//コンストラクタ
Ball::Ball(float posX,float posY){
    GameObject("ball");
    positionX = posX;
    positionY = posY;
    
    //TODO: 初期速度をランダム始める様に変更する(謎エラーで動かん)
//    velocity = new Vector2(((float)rand()/ RAND_MAX),((float)rand()/ RAND_MAX));
    velocity = new Vector2(0,0);


}

//ボールの描画処理
void Ball::Drow(){
    glBegin(GL_POLYGON);
    glVertex2f(positionX, positionY);
    for(int i = 0; i < 360; ++i){
        glVertex2f(positionX + radius * cos(i), positionY + radius * sin(i));
    }
    glEnd();
}


void Ball::Move(){
    positionX += velocity->x * 10;
    positionY += velocity->y * 10;
}

//ボールの衝突判定
void Ball::Collision(){
    
    if(positionY - radius < 0){
        velocity->y *= -1;
    }
    
    if(positionX + radius > WINDOW_WIDTH || positionX - radius < 0){
        velocity->x *= -1;
    }
    
    if(positionY + radius > WINDOW_HEIGHT){
        
        std::cout<< "GameOver" << std::endl;
        GameManager::getInstance().is_finished = true;
        std::cout<< GameManager::getInstance().is_finished << std::endl;
    }
}

void Ball::Collision(Player* player){

    if(abs(this->positionY - player->positionY) < this->radius &&
       player->positionX + player->GetscaleX()/2 > this->positionX &&
       player->positionX - player->GetscaleX()/2 < this->positionX
       ){
        velocity->y *= -1;
    }
}

float Ball::GetRadius(){
    return this->radius;
}



