#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"BulletsSpawner.h"

class BulletsSpawner;

class Player :
	public CharaBase
{
private:
	BulletsSpawner* b_spawner;
	int score;
public:
	Player();
	~Player();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	BulletsSpawner* weapon() { return b_spawner; }
};
