#include"Dxlib.h"
#include"Bullet.h"

Bullet::Bullet(float x,float y,float radius)
{
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
	location.x += speed;
}

void Bullet::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0xffff00, true);
}