//
//  Bar.hpp
//  block-break
//
//  Created by 岡本勇太 on 2017/08/05.
//  Copyright © 2017年 岡本勇太. All rights reserved.
//

#ifndef Bar_hpp
#define Bar_hpp

#include <stdio.h>
#include "System.hpp"

class Bar : public Rect, public Shape
{
public:
    float speed; //移動スピード
    
public:
    Bar(int x, int y, int width, int height) : Rect(x, y, width, height){}
    ~Bar(){}
    virtual void draw();
    void move();
};

#endif /* Bar_hpp */
