#include"Dxlib.h"
#include"Define.h"
#include"Enemy.h"
#include"PadInput.h"
#include"GameMainScene.h"

#define _USE_MATH_DEFINES
#include <math.h>

Enemy::Enemy(int x, int y, bool bossflg)
{
	n_spawner = new NwaySpawner();
	point = 100;
	location.x = x;
	location.y = y;
	boss_flg = bossflg;

	interbal = 0;
	boss_interbal = 0;
	shot_num = 0;
	b_angle = 0.5f;
	delete_time = 5;
	b_type = GetRand(3);
	switch (b_type)
	{
	case 0:
		c_speed = 1.2f;
		break;
	case 1:
		c_speed = 1;
		break;
	case 2:
		c_speed = 0.8f;
		break;
	case 3:
		c_speed = 4;
		break;
	}
	if (boss_flg == false)
	{
		location.radius = 25;
		hp = 5;
		b_num = SINGLE_SHOT;
	}
	else
	{
		location.radius = 100;
		hp = 1000;
		c_speed = 0.5f;
		shot_num = 5;
		b_num = PENTA_SHOT;
	}
	boss_move = 1;

	target_x = x;
	target_y = y;
	angle = 0;
	stop_time = 0;
}
Enemy::~Enemy()
{

}
void Enemy::Update(GameMainScene* g_main)
{
	if (boss_flg == false)
	{
		switch (b_type)
		{
		case 0:
		case 1:
		case 2:
			location.x -= (c_speed);
			if (--interbal < 0)
			{
				weapon()->Shoot(g_main, UpdateBulletData());
				interbal = GetRand(100 + (b_type * 50)) + 50;
			}
			break;
		case 3:
			//目的地に到着したら
			if (target_x-5 <= location.x && target_x + 5 >= location.x && target_y-5 <= location.y && target_y + 5 >= location.y)
			{
				if (--interbal < 0)
				{
					weapon()->Shoot(g_main, UpdateBulletData());
					interbal = 30;
				}
				if (++stop_time > 150)
				{
					//次の目的地を設定
					target_x = GetRand(800) + 400;
					target_y = GetRand(700) + 40;
					stop_time = 0;
				}
			}
			//目的地まで移動
			else
			{
				w = target_x - location.x;
				h = target_y - location.y;
				rad = atan2f(h,w);
				location.x += c_speed * cosf(rad);
				location.y += c_speed * sinf(rad);
			}
			break;
		}
	}
	else
	{
		if (location.x > 1000)
		{
			location.x -= c_speed;
			if (--interbal < 0)
			{
				b_type = 1;
				interbal = GetRand(100) + 50;
				weapon()->Shoot(g_main, UpdateBossBulletData());
			}
		}
		else
		{
			//ボス通常移動
			if (hp > 200)
			{
				if (location.y - location.radius < 0)
				{
					boss_move = 1;
				}
				if (location.y + location.radius > SCREEN_HEIGHT)
				{
					boss_move = -1;
				}
			}
			else
			{
				if (location.y - location.radius < 0)
				{
					boss_move = 2;
				}
				if (location.y + location.radius > SCREEN_HEIGHT)
				{
					boss_move = -2;
				}
			}
			location.y += boss_move;
		}
		//ボス通常攻撃
		if (hp > 200)
		{
			if (--interbal < 0)
			{
				if (--boss_interbal < 0)
				{
					weapon()->Shoot(g_main, UpdateBossBulletData());
					shot_num--;
					boss_interbal = 50;
					if (shot_num <= 0)
					{
						interbal = GetRand(350) + 50;
						shot_num = 5;
						b_type = GetRand(2);
					}
				}
			}
		}
		//ボス発狂
		else
		{
			if (--interbal < 0)
			{
				if (--boss_interbal < 0)
				{
					b_angle = 0.5f;
					weapon()->Shoot(g_main, UpdateBossBulletData());
					b_angle = 0.1f;
					weapon()->Shoot(g_main, UpdateBossBulletData());
					b_angle = 0.9f;
					weapon()->Shoot(g_main, UpdateBossBulletData());
					shot_num--;
					boss_interbal = 50;
					if (shot_num <= 0)
					{
						interbal = GetRand(250) + 50;
						shot_num = 5;
						b_type = GetRand(1);
					}
				}
			}
		}
	}
}

void Enemy::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0xff0000, true);
	DrawFormatString(location.x, location.y, 0xffff00, "%d", hp);
	if (boss_flg == true)
	{
		DrawBox(200, 10, 1200, 60, 0xffffff, true);
		DrawBox(200 + hp, 10, 200, 60, 0xff0000, true);
	}
}

int Enemy::Hit(int damage)
{
	return hp -= damage;
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
	b_data.b_num = b_num;
	b_data.h_count = 1;
	b_data.delete_time = delete_time;
	b_data.b_type = b_type % 3;
	return b_data;
}

BulletData Enemy::UpdateBossBulletData()
{
	BulletData b_data;
	b_data.x = location.x;
	b_data.y = location.y;
	b_data.radius = 10;
	b_data.speed = 0.3f;
	b_data.who = ENEMY_SHOT;
	b_data.b_angle = b_angle;
	b_data.b_num = b_num;
	b_data.h_count = 1;
	b_data.delete_time = 1000;
	b_data.b_type = b_type;
	return b_data;
}