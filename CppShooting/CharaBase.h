#pragma once
#include"SphereCollider.h"

class GameMainScene;

class CharaBase:
	public SphereCollider
{
protected:
	float speed;	//���x
	int image;		//�摜
public:
	virtual void Update(GameMainScene* g_main) = 0;
	virtual void Draw()const = 0;
	virtual void Hit() = 0;
};
