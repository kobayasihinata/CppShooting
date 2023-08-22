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

	virtual void Shoot(GameMainScene* gm_scene, float x, float y, float radius, int who, float angle ,int b_type) = 0;
};



