#pragma once
#include"SphereCollider.h"

class CharaBase:
	public SphereCollider
{
protected:
	float speed;	//���x
	int image;		//�摜
public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual void Hit() = 0;
};
