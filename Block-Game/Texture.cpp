//
//  Texture.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/04.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include "Texture.hpp"
#include <string>

Texture::Texture(){
    positionX = 0;
    positionY = 0;
    
    return;
}

Texture::Texture(float posX,float posY){
    
    GameObject("texture");
    
    positionX = posX;
    positionY = posY;
}

void Texture:: render()
{
    static const GLfloat vtx[] = {
        200, 120,
        400, 120,
        400, 230,
        200, 230,
    };
    glVertexPointer(2, GL_FLOAT, 0, vtx);
    
    // Step5. テクスチャの領域指定
    static const GLfloat texuv[] = {
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
    };
    glTexCoordPointer(2, GL_FLOAT, 0, texuv);
    
    // Step6. テクスチャの画像指定
    glBindTexture(GL_TEXTURE_2D, g_texID);
    
    // Step7. テクスチャの描画
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glDrawArrays(GL_QUADS, 0, 4);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_TEXTURE_2D);
}

void Texture::setupTexture(std::string file, const int width, const int height)
{
    // Step2. 画像データのロード
    std::ifstream fstr(file, std::ios::binary);
    assert(fstr);
    
    const size_t fileSize = static_cast<size_t>(fstr.seekg(0, fstr.end).tellg());
    fstr.seekg(0, fstr.beg);
    std::vector<char> textureBuffer(fileSize);
    fstr.read(&textureBuffer[0], fileSize);
    
    // Step3. 画像データとテクスチャiDを結びつける
    glBindTexture(GL_TEXTURE_2D, g_texID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &textureBuffer[0]);
    
    // Step4. テクスチャの各種設定
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
}


