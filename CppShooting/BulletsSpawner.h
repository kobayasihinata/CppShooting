#pragma once
#include"GameMainScene.h"

class GameMainScene;

class BulletsSpawner
{
protected:
	float speed;			//速度
	float angle;			//角度
	float acceleration;		//加速度
	float angle_velocity;	//角度の変化量
public:
	virtual void Shoot(GameMainScene* gm_scene, int x, int y, int who, float angle ,int b_type) = 0;
};



