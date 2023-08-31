#pragma once
#include "SceneBase.h"

class GameOver :
    public SceneBase
{
private:
    int count;  //ボタン入力間隔
    int score;  //得点格納
    int time;   //時間格納
public:

    //コンストラクタ
    GameOver(int _score, int _time);

    //デストラクタ
    ~GameOver();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

};