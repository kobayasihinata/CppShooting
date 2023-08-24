#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;
class WeaponPickScene;

class Player :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
	int score;		//�_��
	float angle;	//�e�̊p�x
	int power;		//�e�̋���
	int bullet_size;	//�e�̑傫��

	int weapon_type;	//����̎��
	float BaseAngle;	//���˂���ŏ��̒e�̌�����`�悷��p
	float AngleDiff;	//�e���m�̊p�x����`�悷��p

	int b_speed;		//�e�̑��x
	int shot_span;		//�e�̔��ˊԊu
	int player_color;	//�v���C���[�̐F
	int h_count;		//�e���ђʏo����G�̐�
	int delete_time;	//�e�������܂ł̎���

public:
	//�R���X�g���N�^
	Player(int w_type);
	//�f�X�g���N�^
	~Player();
	//�`��ȊO�̍X�V(�Q�[�����C���p)
	void Update(GameMainScene* g_main)override;
	//�`��ȊO�̍X�V(����I����ʗp)
	void Update(WeaponPickScene* w_pick);
	//�`��̍X�V
	void Draw()const override;
	//�e�����������u�Ԃ̏���
	void Hit()override;
	//�v���C���[�̍��W�̎擾
	Location GetLocation() { return location; }
	//NwaySpawner�Ăяo���p
	NwaySpawner* weapon() { return n_spawner; }
	//����̎�ސݒ�
	void SetWeaponType(int type);
	//�v���C���[�̐F�I��
	int GetPlayerColor(int type);
	//�e���˗p�f�[�^���܂Ƃ߂č\���̂�Ԃ�
	BulletData UpdateBulletData();
};
