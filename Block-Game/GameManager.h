//
//  GameManager.h
//  Block-Game
//
//  Created by 内田啓太 on 2017/08/03.
//  Copyright © 2017年 keita_uchida. All rights reserved.
//

#ifndef GameManager_h
#define GameManager_h

#include <stdio.h>



class GameManager {
private:
    GameManager(){}					//コンストラクタを private に置く
    GameManager(const GameManager&);			//コピーコンストラクタも private に置き、定義しない
    GameManager& operator=(const GameManager&);		//コピー代入演算子も private に置き、定義しない
    ~GameManager(){}					//デストラクタを private に置く
public:
    bool is_finished;
    bool is_started;
    
    static GameManager& getInstance(){
        static GameManager inst;
        return inst;
    }
};
#endif /* GameManager_h */
