#pragma once
#include "SceneBase.h"
#include "Title.h"

class GameClear :
    public SceneBase
{
private:

public:

    //�R���X�g���N�^
    GameClear(int score,int time);

    //�f�X�g���N�^
    ~GameClear();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};