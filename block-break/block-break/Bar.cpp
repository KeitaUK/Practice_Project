//
//  Bar.cpp
//  block-break
//
//  Created by 岡本勇太 on 2017/08/05.
//  Copyright © 2017年 岡本勇太. All rights reserved.
//

#include "Bar.hpp"
#include <GLUT/glut.h>

void Bar::move()
{
    
}


void Bar::draw()
{
    glBegin(GL_QUADS);
    glVertex2i(minX,minY);
    glVertex2i(maxX,minY);
    glVertex2i(maxX,maxY);
    glVertex2i(minX,maxY);
    glEnd();
}
