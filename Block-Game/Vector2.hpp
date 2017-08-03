//
//  Vector2.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/29.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef Vector2_hpp
#define Vector2_hpp

#include <stdio.h>

/*二次ベクトルを使いたい時に使うクラス.ポジションやスケールを使う時にも使う。*/
class Vector2{
public:
    Vector2();
    Vector2(float vectorX, float vectorY);
    Vector2(int vectorX, int vectorY);
    
    float x;
    float y;
    
};


#endif /* Vector2_hpp */
