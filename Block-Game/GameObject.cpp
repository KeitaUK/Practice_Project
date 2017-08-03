//
//  GameObject.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/29.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "GameObject.hpp"
#include <string.h>
#include <iostream>

GameObject::GameObject(){
    this->positionX = 0;
    this->positionY = 0;
    
}

GameObject::GameObject(std::string tag){
    this->tag = tag;
    this->positionX = 0;
    this->positionY = 0;
}
