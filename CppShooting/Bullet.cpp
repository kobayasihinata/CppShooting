#include"Dxlib.h"
#include"Bullet.h"

Bullet::Bullet(float x,float y,float radius,int type)
{
	b_type = type;
	location.x = x;
	location.y = y;
	location.radius = radius;
	damage = 0;
	speed = 5;
	angle = 0;
	acceleration = 0;
	angulVelocity = 0;
}
Bullet::~Bullet()
{

}
void Bullet::Update()
{
	switch (b_type)
	{
	case 0:
		location.x += speed;
		break;
	case 1:
		location.x -= speed;
		break;
	default:
		break;
	}
}

void Bullet::Draw()const
{
	switch (b_type)
	{
	case 0:
		DrawCircle(location.x, location.y, location.radius, 0xffff00, true);
		break;
	case 1:
		DrawCircle(location.x, location.y, location.radius, 0xff0000, true);
		break;
	default:
		break;
	}
}