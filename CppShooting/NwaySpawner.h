#pragma once
#include"BulletsSpawner.h"

class NwaySpawner:
	public BulletsSpawner
{
private:
	int numBullets;		//”­Ë‚·‚é’e‚Ì”
	float BaseAngle;	//”­Ë‚·‚éÅ‰‚Ì’e‚ÌŒü‚«
	float AngleDiff;	//’e“¯m‚ÌŠp“x·
public:
	void Shoot(GameMainScene* gm_scene)override;
};
