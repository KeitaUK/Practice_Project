//
//  GameObject.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/29.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <string.h>
#include <iostream>

class GameObject{
public:
    GameObject();
    GameObject(std::string tag);
    
    std::string tag;
    float positionX;
    float positionY;
    
};


#endif /* GameObject_hpp */
