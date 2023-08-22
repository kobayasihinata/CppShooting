#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;

class Player :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
	int score;		//�_��
	float angle;	//�e�̊p�x
	float power;		//�e�̋���
	int bullet_size;	//�e�̑傫��

public:
	Player();
	~Player();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
};
