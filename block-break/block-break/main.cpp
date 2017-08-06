//
//  main.cpp
//  block-break
//
//  Created by 岡本勇太 on 2017/07/31.
//  Copyright © 2017年 岡本勇太. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "Const.hpp"

//プロトタイプ宣言
void display(void);
void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void init(void);

int main (int argc, char * argv[]) {
    
    //GLUT初期化
    glutInit(&argc, argv);
    
    //ウィンドウ作成
    glutInitWindowSize(CWindowSize::WIDTH, CWindowSize::HEIGHT);	//ウィンドウサイズ
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);	//RGBAカラー、zバッファ、ダブルバッファリング
    glutCreateWindow(WINDOW_TITLE);  //ウィンドウを作る
    
    //コールバック関数の登録
    glutDisplayFunc(display);	//再描画時
    glutReshapeFunc(reshape);	//ウィンドウサイズ変更時
    glutKeyboardFunc(keyboard);	//キー入力
    glutKeyboardUpFunc(keyboardUp);	//キーが離された
    
    //初期化
    init();
    
    //メインループ
    glutMainLoop();
    
    return 0;
}


void init(void){
    //　バックバッファをクリアする色(背景色)の指定
    glClearColor(0.5, 0.5, 1.0, 1.0);
    
}


void display(void){
    
}

void reshape(int width, int height){
    
}

void keyboard(unsigned char key, int x, int y){
    
}

void keyboardUp(unsigned char key, int x, int y){
    
}




