#include "Dxlib.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet(float x,float y,float radius,int who, float b_angle)
{
	who_shot = who;
	b_type = 1;
	location.x = x;
	location.y = y;
	location.radius = radius;
	damage = 0;
	speed = 2;
	angle = b_angle;
	acceleration = 0;
	angle_velocity = 0;
	bend_time = 0;
	rad = 0;
}
Bullet::~Bullet()
{

}
void Bullet::Update()
{
	frame++;  //時間測定

	//誰が撃ったかによって方向を変える プレイヤーが１、エネミーがー１なので、X移動量にマクロをかけて動かす

	//弾の種類によって動きを変える
	switch (b_type)
	{
	case SINGLE_SHOT:
		if (++acceleration > 200)
		{
			acceleration = 200;
		}
		rad = angle * (float)M_PI * 2;

		location.x += (speed * cosf(rad)) + acceleration / 50;;
		location.y += (speed * sinf(rad));
		break;
	case BEND_SHOT:
		if (++bend_time < 100)
		{
			if (angle < 1)
			{
				angle += 0.004f;
			}
			else
			{
				angle += 0.002f;
			}
		}
		else if (bend_time < 200)
		{
			if (angle > 1)
			{
				angle -= 0.004f;
			}
			else
			{
				angle -= 0.002f;
			}
		}
		else
		{
			bend_time = 0;
		}
		rad = angle * (float)M_PI * 2;

		location.x += (speed * cosf(rad));
		location.y += (speed * sinf(rad));
		break;
	}
}

void Bullet::Draw()const
{
	switch (who_shot)
	{
	case PLAYER_SHOT:
		DrawCircle(location.x, location.y, location.radius, 0xffff00, true);
		break;
	case ENEMY_SHOT:
		DrawCircle(location.x, location.y, location.radius, 0xff0000, true);
		break;
	default:
		break;
	}
}