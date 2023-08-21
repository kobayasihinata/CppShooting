#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"BulletsSpawner.h"

class BulletsSpawner;

class Enemy :
	public CharaBase
{
private:
	BulletsSpawner* b_spawner;
	int hp;
	int point;

	int interbal;	//’e”­ŽËŠÔŠu
public:
	Enemy(int x,int y);
	~Enemy();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	BulletsSpawner* weapon() { return b_spawner; }
};

