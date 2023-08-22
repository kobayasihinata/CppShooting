#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;

class Player :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
	int score;		//“_”
	float angle;	//’e‚ÌŠp“x
	float power;		//’e‚Ì‹­‚³
	int bullet_size;	//’e‚Ì‘å‚«‚³

public:
	Player();
	~Player();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
};
