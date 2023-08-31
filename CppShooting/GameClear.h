#pragma once
#include "SceneBase.h"
#include "Title.h"

class GameClear :
    public SceneBase
{
private:
    int score;  //得点格納
    int time;   //時間格納
public:

    //コンストラクタ
    GameClear(int _score,int _time);

    //デストラクタ
    ~GameClear();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

};