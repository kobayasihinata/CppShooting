#include "Dxlib.h"
#include "Bullet.h"
#define _USE_MATH_DEFINES
#include <math.h>

Bullet::Bullet(float x,float y,float radius,float speed, int who, float b_angle)
{
	who_shot = who;
	b_type = 0;
	location.x = x;
	location.y = y;
	location.radius = radius;
	damage = 0;
	b_speed = speed;
	angle = b_angle;
	acceleration = 0;
	angle_velocity = 0;
	bend_time = 0;
	rad = 0;
	base_angle = b_angle;
}
Bullet::~Bullet()
{

}
void Bullet::Update()
{
	frame++;  //ŽžŠÔ‘ª’è
	//’e‚ÌŽí—Þ‚É‚æ‚Á‚Ä“®‚«‚ð•Ï‚¦‚é
	switch (b_type)
	{
	case STRAIGHT_SHOT:
		if (++acceleration > 100)
		{
			acceleration = 100;
		}
		rad = angle * (float)M_PI * 2;
		location.x += ((b_speed + acceleration / 20) * cosf(rad));
		location.y += ((b_speed + acceleration / 20) * sinf(rad));
		break;
	case BEND_SHOT:
		if (++bend_time < 100)
		{
			if (angle < base_angle)
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
			if (angle > base_angle)
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

		location.x += (b_speed * cosf(rad));
		location.y += (b_speed * sinf(rad));
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