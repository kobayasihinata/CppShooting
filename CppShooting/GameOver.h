#pragma once
#include "SceneBase.h"

class GameOver :
    public SceneBase
{
private:
    int cursor_y;
    int cursor_num;
    int interval;
public:

    //コンストラクタ
    GameOver();

    //デストラクタ
    ~GameOver();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

};