#pragma once

class CharaBase
{
protected:
	float speed;	//���x
	int image;		//�摜
public:
	virtual void Update();
	virtual void Draw()const;
	virtual void Hit();
};
