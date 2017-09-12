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
void glutSetup(void);
void gameSetup(void);
void onRedisplay(void);
void onReshape(int width, int height);
void onKeyboard(unsigned char key, int x, int y);
void onKeyboardUp(unsigned char key, int x, int y);
void onMouse(int button, int state, int x, int y);
void onMoution(int x, int y);
void onPassiveMotion(int x, int y);
void onSpecial(int key, int x, int y);
void onTimer(int value);


int main (int argc, char * argv[])
{
     //GLUT初期化
    glutInit(&argc, argv);

    //ウィンドウの設定、コールバック登録
    glutSetup();
    
    gameSetup();
    
    //メインループ
    glutMainLoop();
    
    return 0;
}


/*
 * ウィンドウ作成、コールバック登録
 */
void glutSetup(void)
{
    //位置
    glutInitWindowPosition(0, 0);
    
    //サイズ
    glutInitWindowSize(CWindowSize.width, CWindowSize.height);

    //ディスプレイモード
    //（参考）http://wisdom.sakura.ne.jp/system/opengl/gl2.html
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    
    //ウィンドウ生成
    glutCreateWindow(CWindowTitle);
    
    //画面初期化
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho(0, CWindowSize.width, CWindowSize.height, 0, -1, 1);
    
    //コールバック関数の登録
    //（参考）http://wisdom.sakura.ne.jp/system/opengl/gl10.html
    //マウスイベント
    glutMouseFunc(onMouse);
    
    //ボタンが押されている状態のドラッグ中
    glutMotionFunc(onMoution);
    
    //ボタンが押されていない状態のドラッグ中
    glutPassiveMotionFunc(onPassiveMotion);
    
    //キー入力時
    glutKeyboardFunc(onKeyboard);
    
    //キーが離された時
    glutKeyboardUpFunc(onKeyboardUp);

    //文字キー以外の特殊キー入力時
    glutSpecialFunc(onSpecial);

    //ウィンドウサイズ変更時
    glutReshapeFunc(onReshape);
    
    //再描画時
    glutDisplayFunc(onRedisplay);
    
    //タイマー
    glutTimerFunc(CTImeStep, onTimer, 0);
    
    //ウィンドウが閉じられるまでループ
    glutMainLoop();
}


void gameSetup(void)
{

    
}


void Point(int x,int y,float size){
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2i(x , y);
    glEnd();
}


/*
 * 再描画
 */
void callRedisplay()
{
    glutPostRedisplay();
}


/*
 * 再描画時呼ばれる
 */
void onRedisplay(void)
{
    //　バックバッファをクリアする色(背景色)の指定
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glColor4f(0.0f,0.0f,1.0f,1.0f);
//    Point(50,50,2.0);
//    glColor4f(1.0f,0.0f,0.0f,1.0f);
//    Point(250,150,10.0);
//    glFlush();
}


/*
 * ウィンドウサイズ変更時呼ばれる
 */
void onReshape(int width, int height)
{
    
}


 /*
  * マウスイベント
  */
void onKeyboard(unsigned char key, int x, int y)
{
    
}


/*
 * キーが離された時
 */
void onKeyboardUp(unsigned char key, int x, int y)
{
    
}


/*
 * キー入力時
 */
void onMouse(int button, int state, int x, int y)
{
    
}


/*
 * ボタンが押されている状態のドラッグ中
 */
void onMoution(int x, int y)
{
    
}


/*
 * ボタンが押されていない状態のドラッグ中
 */
void onPassiveMotion(int x, int y)
{
    
}


/*
 * 文字キー以外の特殊キー入力時
 */
void onSpecial(int key, int x, int y)
{
    
}


/*
 * タイマー到達時
 */
void onTimer(int value)
{
    //再描画
    callRedisplay();
    
    //再コール
    glutTimerFunc(CTImeStep , onTimer , 0);
}



