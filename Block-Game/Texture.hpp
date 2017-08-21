//
//  Texture.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/04.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <vector>
#include <cassert>
#include <GLUT/GLUT.h>
#include <string>
#include "GameObject.hpp"

const int g_windowWidth  = 640;
const int g_windowHeight = 480;


class Texture : public GameObject{
private:
    
public:
    Texture();
    Texture(float posX,float posY);
    GLuint g_texID;
    void render();
    void setupTexture( std::string file, const int width, const int height);
};

#endif /* Texture_hpp */
