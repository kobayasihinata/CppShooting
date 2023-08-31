#pragma once
#include "SceneBase.h"
#include "Title.h"

class GameClear :
    public SceneBase
{
private:

public:

    //コンストラクタ
    GameClear(int score,int time);

    //デストラクタ
    ~GameClear();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

};