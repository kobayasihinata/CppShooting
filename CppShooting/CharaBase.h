#pragma once
#include"SphereCollider.h"

class GameMainScene;

class CharaBase:
	public SphereCollider
{
protected:
	float c_speed;	//‘¬“x
	int image;		//‰æ‘œ
public:
	virtual void Update(GameMainScene* g_main) = 0;
	virtual void Draw()const = 0;
	virtual int Hit(int damage) = 0;
};
