//
//  main.cpp
//  Block-Game
//
//  Created by 内田啓太 on 2017/07/21.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#include <GLUT/GLUT.h>
#include "player.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "Gui.hpp"
#include <iostream>
#include "Constants.h"
#include "GameManager.h"
#include <string>

//グローバル変数の定義
Player* player;
Ball* ball;
Block* blocks[BLOCK_WIDTH][BLOCK_HEIGHT];


//メソッドの宣言
void display();
void init();
void idle();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);

//描画処理を行うメソッド
void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);

    player->Drow();
    ball->Drow();
    
    //ブロックの描画
    for(int i = 0; i< BLOCK_WIDTH ; i++){
        for(int j = 0; j < BLOCK_HEIGHT; j++){
            if(blocks[i][j]->isHit == false){
                blocks[i][j]->Drow();
            }
        }
    }
        
    if(!GameManager::getInstance().is_started){
        GUI::DrawString("Please push 's' button", WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_WIDTH / 2 - 70, WINDOW_HEIGHT / 2);
    }
    if(GameManager::getInstance().is_finished){
        GUI::DrawString("GameOver", WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_WIDTH / 2 - 70, WINDOW_HEIGHT / 2);
    }
    
    
    glFlush();
}

//初期化処理を行う。
void init(){
    
    player = new Player(WINDOW_WIDTH/2 ,400);
    ball = new Ball(WINDOW_WIDTH/2 , WINDOW_HEIGHT/2);
    GameManager::getInstance().is_started = false;
    GameManager::getInstance().is_finished = false;
    
    for(int i = 0; i< BLOCK_WIDTH ; i++){
        for(int j = 0; j < BLOCK_HEIGHT; j++){
            blocks[i][j] = new Block(WINDOW_WIDTH / BLOCK_WIDTH * i, j);
        }
    }
    
    
    glClearColor(0.0,0.0,0.0, 1.0);

}

//アニメーション処理を行うメソッド
void idle(){
    
    ball->Move();
    ball->Collision();
    ball->Collision(player);
    for(int i = 0; i< BLOCK_WIDTH ; i++){
        for(int j = 0; j < BLOCK_HEIGHT; j++){
            if( blocks[i][j]->isHit == false){
                blocks[i][j]->Collision(ball);
            }
        }
    }
    glutPostRedisplay();   //再描画( ※display()関数を呼び出す関数 )
}

//描画の再定義を行うメソッド
void reshape(int w, int h){             // 座標の定義変更
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 480, 0);         // 左上を　(0, 0) 右下を (640, 480)とする

}

//キーボード入力を受け付ける
void keyboard(unsigned char key, int x, int y)
{    
    if(key == 'a'){
        player->MoveLeft();
    }
    else if(key == 'd'){
        player->MoveRight();
    }
    else if(key == 's'){
        if(!GameManager::getInstance().is_started){
            ball->velocity = new Vector2(0.2f,-0.4f);
            GameManager::getInstance().is_started = true;
        }
    }
    else if(key == 'q'){
        exit(0);
    }
}


int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);  //初期化処理
    glutInitWindowPosition(100, 200);//画面サイズの定義
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);//画面サイズの再定義
    glutCreateWindow(argv[0]);//画面の生成
    glutKeyboardFunc(keyboard);//キーボード入力処理
    glutIdleFunc(idle); //コールバック関数の登録
    init();//初期化処理
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
    return 0;
}
