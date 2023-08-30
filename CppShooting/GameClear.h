#pragma once
#include "SceneBase.h"
#include "Title.h"

class GameClear :
    public SceneBase
{
private:
    int score;
    int time;
    int interval;
public:

    //コンストラクタ
    GameClear();

    //デストラクタ
    ~GameClear();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

};