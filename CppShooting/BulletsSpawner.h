#pragma once
#include"GameMainScene.h"

class BulletsSpawner:
	public GameMainScene
{
private:
	float speed;			//速度
	float angle;			//角度
	float acceleration;		//加速度
	float angulVelocity;	//角度の変化量
public:
	static void Shoot(GameMainScene bspawner);
};



