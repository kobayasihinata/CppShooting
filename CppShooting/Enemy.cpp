#include"Dxlib.h"
#include"Define.h"
#include"Enemy.h"
#include"PadInput.h"

Enemy::Enemy()
{
	hp = 2;
	point = 100;
	speed = 1;
	location.x = 500;
	location.y = 100;
	location.radius = 25;
}
Enemy::~Enemy()
{

}
void Enemy::Update()
{

	//•Ç‚É‚Ô‚Â‚©‚é
	if (location.x - location.radius < 0)
	{
		location.x = 0 + location.radius;
	}
	if (location.x + location.radius > SCREEN_WIDTH)
	{
		location.x = SCREEN_WIDTH - location.radius;
	}
	if (location.y - location.radius < 0)
	{
		location.y = 0 + location.radius;
	}
	if (location.y + location.radius > SCREEN_HEIGHT)
	{
		location.y = SCREEN_HEIGHT - location.radius;
	}
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0xff0000, true);
}

void Enemy::Hit()
{

}