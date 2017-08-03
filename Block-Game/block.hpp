//
//  block.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/22.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef block_hpp
#define block_hpp
#include <string>
#include <stdio.h>
#include "GameObject.hpp"
#include "ball.hpp"

class Block : public GameObject{
public:
    Block();
    Block(float posX,float posY);
    bool isHit = false;

    
    void Drow();
    void Collision(Ball* ball);
    float GetInterval();
    float GetScaleX();
    float GetScaleY();
    
private:
    float scaleX = 50.0f;
    float scaleY = 30.0f;
    float interval = 10.0f;
    
};

#endif /* block_hpp */
