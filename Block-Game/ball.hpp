//
//  ball.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/21.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include "Vector2.hpp"
#include "GameObject.hpp"
#include "player.hpp"

//#define RAND_MAX 20;

class Ball: public GameObject{
public:
    Ball(float posX,float posY);
    
    Vector2* velocity;
    void Draw();
    void Move();
    void Collision();
    void Collision(Player* player);
    float GetRadius();
    
private:
    float radius = 10;
    
};

#endif /* ball_hpp */
