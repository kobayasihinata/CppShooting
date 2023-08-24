#pragma once
#include"GameMainScene.h"

class GameMainScene;

class BulletsSpawner
{
protected:
	float speed;			//���x
	float angle;			//�p�x
	float acceleration;		//�����x
	float angle_velocity;	//�p�x�̕ω���
public:

	virtual void Shoot(GameMainScene* gm_scene, BulletData b_data) = 0;
};



