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
	float power;		//�e�̋���
	int bullet_size;	//�e�̑傫��

	int weapon_type;	//����̎��
	float BaseAngle;	//���˂���ŏ��̒e�̌�����`�悷��p
	float AngleDiff;	//�e���m�̊p�x����`�悷��p

	int b_speed;		//�e�̑��x
	int shot_span;		//�e�̔��ˊԊu

public:

	Player();
	~Player();
	void Update(GameMainScene* g_main)override;
	void Update(WeaponPickScene* w_pick);
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
	void SetWeaponType(int type) { weapon_type = type; }
};
