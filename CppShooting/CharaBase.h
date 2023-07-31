#pragma once

class CharaBase
{
protected:
	float speed;	//‘¬“x
	int image;		//‰æ‘œ
public:
	virtual void Update();
	virtual void Draw()const;
	virtual void Hit();
};
