#pragma once
#include"GameMainScene.h"

class GameMainScene;

class BulletsSpawner
{
private:
	float speed;			//‘¬“x
	float angle;			//Šp“x
	float acceleration;		//‰Á‘¬“x
	float angulVelocity;	//Šp“x‚Ì•Ï‰»—Ê
public:
	virtual void Shoot(GameMainScene* gm_scene, int x, int y, int type);
};



