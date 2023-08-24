#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "PadInput.h"

#include "Player.h"

class Player;
class Bullet;

class WeaponPickScene:
	public SceneBase
{
private:
	Player* player;
	Bullet* bullet[MAX_BULLET];	
	int pick_cursor;			//����I���J�[�\���̈ʒu
	int now_current;			//�I�𒆂̕���
	int move_span;				//�J�[�\���𓮂��������Ȃ��p
	bool try_flg;				//���˒������i
	
	bool enter_flg;				//���팈��m�F��ʂ֍s�������f
public:
	//�R���X�g���N�^
	WeaponPickScene();

	//�f�X�g���N�^
	~WeaponPickScene();

	//�`��ȊO�̍X�V
	SceneBase* Update()override;

	//�`��̍X�V
	void Draw()const override;

	//�e�̔z��ɐV�����f�[�^���쐬����i�X�|�[������X���W�AY���W�A�e�̔��a�A�e�̑��x�A�N���ł��o�������A�e�̈ړ��p�x�j
	void SpawnBullet(BulletData b_data);
};