#pragma once
#include "SceneBase.h"

class GameOver :
    public SceneBase
{
private:

public:

    //�R���X�g���N�^
    GameOver();

    //�f�X�g���N�^
    ~GameOver();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};