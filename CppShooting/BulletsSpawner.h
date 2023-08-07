#pragma once
#include"GameMainScene.h"

class BulletsSpawner:
	public GameMainScene
{
private:
	float speed;			//‘¬“x
	float angle;			//Šp“x
	float acceleration;		//‰Á‘¬“x
	float angulVelocity;	//Šp“x‚Ì•Ï‰»—Ê
public:
	static void Shoot(GameMainScene bspawner);
};



