#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"

class Player :
	public CharaBase
{
private:
	int score;
public:
	Player();
	~Player();
	void Update()override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
};
