#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"

class Enemy :
	public CharaBase
{
private:
	int hp;
	int point;

	int interbal;	//’e”­ŽËŠÔŠu
public:
	Enemy(int x,int y);
	~Enemy();
	void Update()override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
};

