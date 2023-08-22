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
	int score;		//点数
	float angle;	//弾の角度
	float power;		//弾の強さ
	int bullet_size;	//弾の大きさ

public:
	Player();
	~Player();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
};
