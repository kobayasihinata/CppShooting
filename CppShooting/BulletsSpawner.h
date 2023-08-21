#pragma once
#include"GameMainScene.h"

class GameMainScene;

class BulletsSpawner
{
private:
	float speed;			//���x
	float angle;			//�p�x
	float acceleration;		//�����x
	float angulVelocity;	//�p�x�̕ω���
public:
	virtual void Shoot(GameMainScene* gm_scene, int x, int y, int type);
};



