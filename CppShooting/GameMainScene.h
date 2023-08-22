#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "PadInput.h"

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Player;
class Enemy;

class GameMainScene :
    public SceneBase
{
private:
    Player* player;
    Enemy* enemy[MAX_ENEMY];
    Bullet* bullet[MAX_BULLET];

    int enemy_spawn_int;    //�G�o���Ԋu
    int time;               //
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

    //�e�̔z��ɐV�����f�[�^���쐬����i�X�|�[������X���W�AY���W�A�e�̔��a�A�N���ł��o�������A�e�̈ړ��p�x�j
    void SpawnBullet(float x, float y,int radius,int who, float angle);
};



