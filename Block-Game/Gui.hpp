//
//  Gui.hpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/02.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef Gui_hpp
#define Gui_hpp

#include <stdio.h>
#include <string>

class GUI{
public:
    GUI();
    static void DrawString(std::string str, int w, int h, int x0, int y0);
};

#endif /* Gui_hpp */
