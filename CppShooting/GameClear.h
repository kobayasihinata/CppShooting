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

    //�R���X�g���N�^
    GameClear();

    //�f�X�g���N�^
    ~GameClear();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};