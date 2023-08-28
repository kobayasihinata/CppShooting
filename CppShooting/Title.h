#pragma once
#include "SceneBase.h"
#include "GameMainScene.h"

#define TITLEMODESELECT_X 165
#define TITLEMODESELECT_Y 270

class Title :
    public SceneBase
{
private:
    int cursor_y;
    int cursor_num;
    int interval;
public:

    //コンストラクタ
    Title();

    //デストラクタ
    ~Title();

    //描画以外の更新
    SceneBase* Update()override;

    //描画の更新
    void Draw()const override;

};




