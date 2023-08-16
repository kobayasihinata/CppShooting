#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "PadInput.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "NwaySpawner.h"

class GameMainScene :
    public SceneBase
{
private:
    Player* player;
    Enemy* enemy[MAX_ENEMY];

    int enemy_spawn_int;    //�G�o���Ԋu

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
    static void SpawnBullet(int x,int y,int radius,int type);
};



