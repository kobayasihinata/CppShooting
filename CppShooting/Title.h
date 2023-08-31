#pragma once
#include "SceneBase.h"
#include "GameMainScene.h"

#define TITLEMODESELECT_X 780
#define TITLEMODESELECT_Y 300

class Title :
    public SceneBase
{
private:
    int cursor_y;   //カーソルのY座標
    int cursor_num; //カーソルの番号
    int s_interval; //スティックの入力間隔
    int b_interval; //ボタンの入力間隔
    int cursor_anim;//カーソルのアニメーション用
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




