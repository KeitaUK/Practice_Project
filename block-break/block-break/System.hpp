//
//  System.hpp
//  block-break
//
//  Created by 岡本勇太 on 2017/09/12.
//  Copyright © 2017年 岡本勇太. All rights reserved.
//

#ifndef System_hpp
#define System_hpp

#include <stdio.h>

//矩形
struct Size
{
    int width;
    int height;
};

//2次元座標
struct Vector2
{
    int x;
    int y;
};

//3次元座標
struct Vector3
{
    int x;
    int y;
    int z;
};

//描画インターフェイス
struct Shape
{
public:
    virtual void draw() = 0;
};

//矩形
struct Rect
{
public:
    int x; //中心座標x
    int y; //中心座標y
    int width;
    int height;
    
    int minX, minY, maxX, maxY;
    
    Rect(int x, int y, int width, int height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        
        minX = x - width/2;
        maxX = x + width/2;
        minY = y - height/2;
        maxY = y + height/2;
    }
    ~Rect();
};

//円
struct Circle
{
    int x;
    int y;
    int radius;
};

#endif /* System_hpp */
