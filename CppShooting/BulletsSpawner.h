#pragma once
#include"GameMainScene.h"

class GameMainScene;

class BulletsSpawner
{
protected:
	float speed;			//‘¬“x
	float angle;			//Šp“x
	float acceleration;		//‰Á‘¬“x
	float angle_velocity;	//Šp“x‚Ì•Ï‰»—Ê
public:

	virtual void Shoot(GameMainScene* gm_scene, BulletData b_data) = 0;
};



