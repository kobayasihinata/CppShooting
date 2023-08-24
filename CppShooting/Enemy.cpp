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
	b_angle = 0.5;
	delete_time = 5;
	b_type = GetRand(2);
}
Enemy::~Enemy()
{

}
void Enemy::Update(GameMainScene* g_main)
{
	location.x -= 0.5f;
	if (--interbal < 0)
	{
		weapon()->Shoot(g_main, UpdateBulletData());
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

BulletData Enemy::UpdateBulletData()
{
	BulletData b_data;
	b_data.x = location.x;
	b_data.y = location.y;
	b_data.radius = 10;
	b_data.speed = 1;
	b_data.who = ENEMY_SHOT;
	b_data.b_angle = b_angle;
	b_data.b_num = SINGLE_SHOT;
	b_data.h_count = 1;
	b_data.delete_time = delete_time;
	b_data.b_type = b_type;
	return b_data;
}