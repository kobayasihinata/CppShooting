#pragma once
#include "SceneBase.h"

class GameMainScene :
    public SceneBase
{
private:


public:

    //�R���X�g���N�^
    GameMainScene();

    //�f�X�g���N�^
    ~GameMainScene();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

    //�e/�v���C���[/�G�̓����蔻��̃`�F�b�N���s��
    void HitCheck();

    //�e�̔z��ɐV�����f�[�^���쐬����
    void SpawnBullet();
};



