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
	location.x--;
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0xff0000, true);
}

void Enemy::Hit()
{

}