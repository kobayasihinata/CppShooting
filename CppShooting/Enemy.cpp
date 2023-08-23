#include"Dxlib.h"
#include"Define.h"
#include"Enemy.h"
#include"PadInput.h"
#include"GameMainScene.h"

Enemy::Enemy(int x, int y)
{
	n_spawner = new NwaySpawner();
	hp = 2;
	point = 100;
	c_speed = 1;
	location.x = x;
	location.y = y;
	location.radius = 25;

	interbal = 0;
}
Enemy::~Enemy()
{

}
void Enemy::Update(GameMainScene* g_main)
{
	location.x -= 0.5f;
	if (--interbal < 0)
	{
		weapon()->Shoot(g_main, location.x, location.y, 10,1,ENEMY_SHOT,0.5f,SINGLE_SHOT);
		interbal = GetRand(200)+50;
	}
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0xff0000, true);
}

void Enemy::Hit()
{
	location.x = GetRand(600)+300;
	location.y = GetRand(600)+50;
}