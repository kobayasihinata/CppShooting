#pragma once
#include"GameMainScene.h"

class BulletsSpawner:
	public GameMainScene
{
private:
	float speed;			//���x
	float angle;			//�p�x
	float acceleration;		//�����x
	float angulVelocity;	//�p�x�̕ω���
public:
	static void Shoot(GameMainScene bspawner);
};



