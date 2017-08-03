//
//  Vector2.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/29.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "Vector2.hpp"


Vector2::Vector2(){
    this->x = 0;
    this->y = 0;
    
}

Vector2::Vector2(float vectorX, float vectorY){
    this->x = vectorX;
    this->y = vectorY;
}

Vector2::Vector2(int vectorX, int vectorY){
    this->x = (float)vectorX;
    this->y = (float)vectorY;
}
