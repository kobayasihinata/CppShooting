#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;

class Enemy :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
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
	NwaySpawner* weapon() { return n_spawner; }
};

