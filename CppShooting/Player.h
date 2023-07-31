#pragma once
#include"CharaBase.h"

class Player:
	public CharaBase
{
private:
	int score;
public:
	void Update()override;
	void Draw()const override;
	void Hit()override;
};
