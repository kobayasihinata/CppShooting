#pragma once
#include "SceneBase.h"
#include "define.h"
#include "PadInput.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletsSpawner.h"

class GameMainScene :
    public SceneBase
{
private:
    Player* player;
    Enemy* enemy;
    Bullet* bullet[MAX_BULLET];

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



