//
//  player.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/21.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef player_hpp
#define player_hpp
#include "GameObject.hpp"
#include <string>
#include <stdio.h>


class Player : public GameObject{
public:
    Player(float posX,float posY);
    float moveX = 5;

    
    void Drow();
    void MoveRight();
    void MoveLeft();
    float GetscaleX();
    float GetscaleY();
    
private:
    float scaleX = 100;
    float scaleY = 30;
    
};

#endif /* player_hpp */
