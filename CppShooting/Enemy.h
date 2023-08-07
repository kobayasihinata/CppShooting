#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"

class Enemy :
	public CharaBase
{
private:
	int hp;
	int point;
public:
	Enemy();
	~Enemy();
	void Update()override;
	void Draw()const override;
	void Hit()override;
};

