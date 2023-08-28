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

    //�R���X�g���N�^
    Title();

    //�f�X�g���N�^
    ~Title();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};




