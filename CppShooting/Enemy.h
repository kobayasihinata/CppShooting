#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;

class Enemy :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
	int hp;
	int point;

	int interbal;		//�e���ˊԊu
	int boss_interbal;	//�e�A�����ˊ�
	int shot_num;		//���̔��˂ŉ���e���o�邩
	float b_angle;		//�e�p�x
	int delete_time;	//�e�������܂ł̎���
	int b_type;			//�e�̎��
	int b_num;			//�e�̎��
	bool boss_flg;		//�{�X���ǂ���
	int boss_move;		//�{�X�̏㉺�ړ�

	int target_x;		//�������ʒu
	int target_y;		//�������ʒu
	float angle;		//�G�̈ړ�����
	float rad;			//�p�x�v�Z�p
	float w;			//�p�x�v�Z�p
	float h;			//�p�x�v�Z�p
	int stop_time;		//��~����
	float spawn_y;		//�X�|�[�������ʒu�iY���W�j

public:
	Enemy(int x, int y, bool bossflg, bool f_flg);
	~Enemy();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	int Hit(int damage)override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
	//�e���˗p�f�[�^���܂Ƃ߂č\���̂�Ԃ�
	BulletData UpdateBulletData();
	//�e���˗p�f�[�^���܂Ƃ߂č\���̂�Ԃ��i�{�X�p�e�j
	BulletData UpdateBossBulletData();
};

