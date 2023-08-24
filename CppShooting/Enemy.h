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

	int interbal;	//�e���ˊԊu
	float b_angle;	//�e�p�x
	int delete_time;//�e�������܂ł̎���
	int b_type;		//�e�̎��
public:
	Enemy(int x,int y);
	~Enemy();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
	//�e���˗p�f�[�^���܂Ƃ߂č\���̂�Ԃ�
	BulletData UpdateBulletData();
};

