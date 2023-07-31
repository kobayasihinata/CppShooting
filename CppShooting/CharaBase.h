#pragma once

class CharaBase
{
protected:
	float speed;	//���x
	int image;		//�摜
public:
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual void Hit() = 0;
};
