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

Player::Player(int w_type)
{
	n_spawner = new NwaySpawner();

	score = 0;
	location.x = 100;
	location.y = 100;
	location.radius = 25;

	weapon_type = w_type;
	c_speed = weapon_type / 1.2f;
	switch (weapon_type)
	{
	case 1:
		b_speed = 10;
		delete_time = 100;
		break;
	case 2:
		b_speed = 1;
		delete_time = 6;
		break;
	case 3:
		b_speed = 1;
		delete_time = 5;
		break;
	case 4:
		b_speed = 1;
		delete_time = 4;
		break;
	case 5:
		b_speed = 1;
		delete_time = 3;
		break;
	}
	angle = 1;
	power = 0;
	bullet_size = 10;
	AngleDiff = 0.08f;
	BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
	shot_span = 0;
	player_color = GetPlayerColor(weapon_type);
	h_count = 1;
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

	//弾の発射
	switch (weapon_type)
	{
	case 1:
		if (--shot_span <= 0 && PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			shot_span = 30;
			h_count = 100;
			weapon()->Shoot(g_main, UpdateBulletData());
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
		AngleDiff = 0.08f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	case 2:
		if (--shot_span <= 0 && PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			h_count = bullet_size / 10;
			delete_time = 6 - h_count;
			weapon()->Shoot(g_main, UpdateBulletData());
		}
		//チャージショット
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			power++;
		}
		else
		{
			power = 0;
			b_speed = 1;
		}
		if (power < 100)
		{
			bullet_size = 10;
			b_speed = 2;
		}
		else if (power < 200)
		{
			bullet_size = 20;
			b_speed = 3;
		}
		else if (power < 400)
		{
			bullet_size = 40;
			b_speed = 4;
		}
		break;
	case 3:
		if (--shot_span <= 0 && PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
		{
			shot_span = 60;
			h_count = bullet_size / 10;
			delete_time = 6-h_count;
			weapon()->Shoot(g_main, UpdateBulletData());
		}
		//チャージショット
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			power++;
		}
		else
		{
			power = 0;
			b_speed = 1;
		}
		if (power < 200)
		{
			bullet_size = 10;
			b_speed = 2;
		}
		else if (power < 300)
		{
			bullet_size = 20;
			b_speed = 3;
		}
		else if (power < 600)
		{
			bullet_size = 40;
			b_speed = 5;
		}
		break;
	case 4:
		if (--shot_span <= 0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			h_count = 1;
			weapon()->Shoot(g_main, UpdateBulletData());
		}
		break;
	case 5:
		if (--shot_span <= 0 &&PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			h_count = 1;
			weapon()->Shoot(g_main, UpdateBulletData());
		}
		break;
	}
}

void Player::Update(WeaponPickScene* w_pick) {
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

	//弾の発射
	switch (weapon_type)
	{
	case 1:
		if (--shot_span <= 0 && PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			shot_span = 30;
			h_count = 100;
			weapon()->Shoot(w_pick, UpdateBulletData());
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
		AngleDiff = 0.08f;
		BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
		break;
	case 2:
		if (--shot_span <= 0 && PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			h_count = bullet_size / 10;
			delete_time = 6 - h_count;
			weapon()->Shoot(w_pick, UpdateBulletData());
		}
		//チャージショット
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			power++;
		}
		else
		{
			power = 0;
			b_speed = 1;
		}
		if (power < 100)
		{
			bullet_size = 10;
			b_speed = 2;
		}
		else if (power < 200)
		{
			bullet_size = 20;
			b_speed = 3;
		}
		else if (power < 400)
		{
			bullet_size = 40;
			b_speed = 4;
		}
		break;
	case 3:
		if (--shot_span <= 0 && PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
		{
			shot_span = 60;
			h_count = bullet_size / 10;
			delete_time = 6 - h_count;
			weapon()->Shoot(w_pick, UpdateBulletData());
		}
		//チャージショット
		if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			power++;
		}
		else
		{
			power = 0;
			b_speed = 1;
		}
		if (power < 200)
		{
			bullet_size = 10;
			b_speed = 2;
		}
		else if (power < 300)
		{
			bullet_size = 20;
			b_speed = 3;
		}
		else if (power < 600)
		{
			bullet_size = 40;
			b_speed = 5;
		}
		break;
	case 4:
		if (--shot_span <= 0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			h_count = 1;
			weapon()->Shoot(w_pick, UpdateBulletData());
		}
		break;
	case 5:
		if (--shot_span <= 0 && PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
		{
			shot_span = 40;
			h_count = 1;
			weapon()->Shoot(w_pick, UpdateBulletData());
		}
		break;
	}
}

void Player::Draw()const
{
	DrawFormatString(0, 20, 0xffffff, "%d", weapon_type);
	DrawCircle(location.x, location.y, location.radius, player_color, true);
	for (int i = 0; i < weapon_type; i++)
	{
		DrawLine(location.x, location.y, location.x + (cosf((BaseAngle + (i * AngleDiff)) * (float)M_PI * 2) * 60), location.y + (sinf((BaseAngle + (i * AngleDiff)) * (float)M_PI * 2) * 60), player_color);
	}
	if (power > 0.1f)
	{
		DrawCircle(location.x, location.y, 100 - (power % 100), player_color, false);
		DrawCircle(location.x, location.y, bullet_size+1, 0x000000, true);
		DrawCircle(location.x, location.y, bullet_size, player_color, true);
	}

}

void Player::Hit()
{
	location.x = 100;
	location.y = 100;
}

void Player::SetWeaponType(int type)
{
	weapon_type = type;
	c_speed = weapon_type / 1.2f;
	player_color = GetPlayerColor(weapon_type);
	angle = 1;
	switch (weapon_type)
	{
	case 1:
		b_speed = 10;
		delete_time = 100;
		break;
	case 2:
		b_speed = 1;
		delete_time = 6;
		break;
	case 3:
		b_speed = 1;
		delete_time = 5;
		break;
	case 4:
		b_speed = 1;
		delete_time = 4;
		break;
	case 5:
		b_speed = 1;
		delete_time = 3;
		break;
	}
	angle = 1;
	AngleDiff = 0.08f;
	BaseAngle = angle - ((AngleDiff * weapon_type) / 2) + AngleDiff / 2;
}
int Player::GetPlayerColor(int type)
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
	default:
		return 0;
	}
}

BulletData Player::UpdateBulletData()
{
	BulletData b_data;
	b_data.x = location.x;
	b_data.y = location.y; 
	b_data.radius = bullet_size;
	b_data.speed = b_speed;
	b_data.who = weapon_type;
	b_data.b_angle = angle; 
	b_data.b_num = weapon_type; 
	b_data.h_count = h_count;
	b_data.delete_time = delete_time;
	b_data.b_type = 0;
	return b_data;
}
