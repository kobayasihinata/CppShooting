#include"Dxlib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include"Define.h"
#include"Player.h"
#include"PadInput.h"
#include"GameMainScene.h"
#include"WeaponPickScene.h"

#define PLAYER_MOVE_SPEED (15000-(c_speed*1000))
#define PLAYER_FRONT_X(front)    (location.x + front * cosf(angle * (float)M_PI * 2))
#define PLAYER_FRONT_Y(front)   (location.y + front * sinf(angle * (float)M_PI * 2))

Player::Player()
{
	n_spawner = new NwaySpawner();

	score = 0;
	c_speed = 1;
	location.x = 100;
	location.y = 100;
	location.radius = 25;

	weapon_type = 1;

	switch (weapon_type)
	{
	case 1:
		b_speed = 10;
		break;
	case 2:
		b_speed = 6;
		break;
	case 3:
		b_speed = 5;
		break;
	case 4:
		b_speed = 3;
		break;
	case 5:
		b_speed = 2;
		break;
	}
	angle = 1;
	power = 0;
	bullet_size = 10;
	AngleDiff = 0.05f;
	BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
	shot_span = 0;
}
Player::~Player()
{

}
void Player::Update(GameMainScene* g_main)
{
	//移動
	if (PAD_INPUT::GetLStick().ThumbY >= 5000 || PAD_INPUT::GetLStick().ThumbY <= -5000)
	{
		location.y -= PAD_INPUT::GetLStick().ThumbY / PLAYER_MOVE_SPEED;
	}
	if (PAD_INPUT::GetLStick().ThumbX >= 5000 || PAD_INPUT::GetLStick().ThumbX <= -5000)
	{
		location.x += PAD_INPUT::GetLStick().ThumbX / PLAYER_MOVE_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		location.y--;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		location.y++;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		location.x--;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		location.x++;
	}

	//壁にぶつかる
	if (location.x-location.radius < 0)
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
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		if (++weapon_type > 5)
		{
			weapon_type = 1;
		}
	}
	switch (weapon_type)
	{
	case 1:
		b_speed = 10;
		if (--shot_span <= 0 && PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			weapon()->Shoot(g_main, location.x, location.y, bullet_size, b_speed, PLAYER_SHOT, angle, weapon_type);
		}
		//弾を撃つ角度変更
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_LEFT_SHOULDER))
		{
			angle -= 0.001f;
		}
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_RIGHT_SHOULDER))
		{
			angle += 0.001f;
		}
		AngleDiff = 0.05f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	case 2:
	case 3:
		b_speed = 5;
		if (--shot_span <= 0 && PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			weapon()->Shoot(g_main, location.x, location.y, bullet_size, b_speed, PLAYER_SHOT, angle, weapon_type);
		}
		//チャージショット
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			power += 0.1f;
		}
		else
		{
			power = 0;
		}
		if (power < 10)
		{
			bullet_size = 10;
		}
		else if (power < 20)
		{
			bullet_size = 20;
		}
		else if (power < 40)
		{
			bullet_size = 40;
		}
		AngleDiff = 0.05f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	case 4:
	case 5:
		b_speed = 1;
		if (--shot_span <= 0 &&PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			weapon()->Shoot(g_main, location.x, location.y, bullet_size, b_speed, PLAYER_SHOT, angle, weapon_type);
		}
		AngleDiff = 0.05f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	}
}

void Player::Update(WeaponPickScene* w_pick)
{
	//移動
	if (PAD_INPUT::GetLStick().ThumbY >= 5000 || PAD_INPUT::GetLStick().ThumbY <= -5000)
	{
		location.y -= PAD_INPUT::GetLStick().ThumbY / PLAYER_MOVE_SPEED;
	}
	if (PAD_INPUT::GetLStick().ThumbX >= 5000 || PAD_INPUT::GetLStick().ThumbX <= -5000)
	{
		location.x += PAD_INPUT::GetLStick().ThumbX / PLAYER_MOVE_SPEED;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		location.y--;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		location.y++;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		location.x--;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		location.x++;
	}

	//壁にぶつかる
	if (location.x - location.radius < 0)
	{
		location.x = 0 + location.radius;
	}
	if (location.x + location.radius > SCREEN_WIDTH-400)
	{
		location.x = SCREEN_WIDTH - 400 - location.radius;
	}
	if (location.y - location.radius < 0)
	{
		location.y = 0 + location.radius;
	}
	if (location.y + location.radius > SCREEN_HEIGHT-200)
	{
		location.y = SCREEN_HEIGHT - 200 - location.radius;
	}
	switch (weapon_type)
	{
	case 1:
		b_speed = 10;
		if (--shot_span <= 0 && PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			weapon()->Shoot(w_pick, location.x, location.y, bullet_size, b_speed, PLAYER_SHOT, angle, weapon_type);
		}
		//弾を撃つ角度変更
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_LEFT_SHOULDER))
		{
			angle -= 0.001f;
		}
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_RIGHT_SHOULDER))
		{
			angle += 0.001f;
		}
		AngleDiff = 0.05f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	case 2:
	case 3:
		b_speed = 5;
		angle = 1;
		if (--shot_span <= 0 && PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			weapon()->Shoot(w_pick, location.x, location.y, bullet_size, b_speed, PLAYER_SHOT, angle, weapon_type);
		}
		//チャージショット
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			power += 0.1f;
		}
		else
		{
			power = 0;
		}
		if (power < 10)
		{
			bullet_size = 10;
		}
		else if (power < 20)
		{
			bullet_size = 20;
		}
		else if (power < 40)
		{
			bullet_size = 40;
		}
		AngleDiff = 0.05f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	case 4:
	case 5:
		b_speed = 1;
		angle = 1;
		if (--shot_span <= 0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			weapon()->Shoot(w_pick, location.x, location.y, bullet_size, b_speed, PLAYER_SHOT, angle, weapon_type);
		}
		AngleDiff = 0.05f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	}
}

void Player::Draw()const
{
	DrawFormatString(0, 20, 0xffffff, "%d", weapon_type);
	DrawCircle(location.x, location.y, location.radius, 0x00ff00, true);
	for (int i = 0; i < weapon_type; i++)
	{
		DrawLine(location.x, location.y, location.x + (cosf((BaseAngle + (i * AngleDiff)) * (float)M_PI * 2) * 60), location.y + (sinf((BaseAngle + (i * AngleDiff)) * (float)M_PI * 2) * 60), 0x00ff00);
	}
	if (power > 0.1f)
	{
		DrawCircle(location.x, location.y, bullet_size, 0xffff00, true);
	}

}

void Player::Hit()
{
	location.x = 100;
	location.y = 100;
}
