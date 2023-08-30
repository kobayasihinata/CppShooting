#include "Dxlib.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet(BulletData b_data)
{
	who_shot = b_data.who;
	b_type = b_data.b_type;
	location.x = b_data.x;
	location.y = b_data.y;
	location.radius = b_data.radius;
	damage = b_data.radius/5;
	b_speed = b_data.speed;
	angle = b_data.b_angle;
	acceleration = 0;
	angle_velocity = 0;
	bend_time = 0;
	rad = 0;
	base_angle = b_data.b_angle;
	hit_count = b_data.h_count;
	b_color = GetBulletColor(b_data.who);
	delete_time = b_data.delete_time;
}
Bullet::~Bullet()
{

}
void Bullet::Update(float player_x, float player_y)
{
	frame++;  //時間測定
	if (frame % 60 == 0)
	{
		delete_time--;	//弾を消すまでのカウントダウン
	}
	//弾の種類によって動きを変える
	switch (b_type)
	{
	case STRAIGHT_SHOT:
		if (++acceleration > 50)
		{
			acceleration = 50;
		}
		rad = angle * (float)M_PI * 2;
		location.x += ((b_speed + acceleration * 0.08) * cosf(rad));
		location.y += ((b_speed + acceleration * 0.08) * sinf(rad));
		break;
	case BEND_SHOT:
		if (++bend_time < 25)
		{
			if (angle < base_angle)
			{
				angle += 0.016f;
			}
			else
			{
				angle += 0.008f;
			}
		}
		else if (bend_time < 50)
		{
			if (angle > base_angle)
			{
				angle -= 0.016f;
			}
			else
			{
				angle -= 0.008f;
			}
		}
		else
		{
			bend_time = 0;
		}
		if (++acceleration > 50)
		{
			acceleration = 50;
		}
		rad = angle * (float)M_PI * 2;
		location.x += ((b_speed + acceleration * 0.08) * cosf(rad));
		location.y += ((b_speed + acceleration * 0.08) * sinf(rad));
		break;
	case CHASING_SHOT:
		if (++acceleration > 50)
		{
			acceleration = 50;
		}
		if (player_y - location.y > 20) 
		{ 
			if (angle > 0.35)
			{
				angle -= 0.002;
			}
		}
		if (player_y - location.y < -20)
		{
			if (angle < 0.65)
			{
				angle += 0.002;
			}
		}
		rad = angle * (float)M_PI * 2;
		location.x += ((b_speed + acceleration * 0.08) * cosf(rad));
		location.y += ((b_speed + acceleration * 0.08) * sinf(rad));
		break;
	}
}

void Bullet::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, b_color, true);
}

int Bullet::GetBulletColor(int type)
{
	switch (type)
	{
	case 1:
		return GetColor(0, 100, 255);
	case 2:
		return GetColor(0, 255, 255);
	case 3:
		return GetColor(0, 255, 0);
	case 4:
		return GetColor(255, 255, 0);
	case 5:
		return GetColor(255, 125, 0);
	case 6:
		return GetColor(255, 0, 0);
	default:
		return 0;
	}
}