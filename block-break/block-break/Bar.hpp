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

class Bar{
private:
    int x,y; //座標
    float speed; //移動スピード
    
private:
    void draw();
    void move();
    
public:
    Bar(){
        x = 100;
        y = 100;
    }
    ~Bar();
    void setSpeed(float s);
};

#endif /* Bar_hpp */
