#pragma once
#include"GameMainScene.h"

class BulletsSpawner
{
private:
	float speed;			//���x
	float angle;			//�p�x
	float acceleration;		//�����x
	float angulVelocity;	//�p�x�̕ω���
public:
	virtual void Shoot() = 0;
};



