//
//  item.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/03.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef item_hpp
#define item_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Item:public GameObject{
public:
    Item();
    Item(float posX, float posY);
    
    float scaleX = 10;
    float scaleY = 10;
    
    
    void Draw();
    void Destroy();
};

#endif /* item_hpp */
