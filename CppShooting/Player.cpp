#include"Dxlib.h"
#define _USE_MATH_DEFINES
#include <math.h>

#include"Define.h"
#include"Player.h"
#include"PadInput.h"
#include"GameMainScene.h"

#define PLAYER_MOVE_SPEED (15000-(c_speed*1000))

Player::Player()
{
	n_spawner = new NwaySpawner();

	score = 0;
	c_speed = 1;
	location.x = 100;
	location.y = 100;
	location.radius = 25;

	angle = 1;
	power = 0;
	bullet_size = 0;
}
Player::~Player()
{

}
void Player::Update(GameMainScene* g_main)
{
	//ˆÚ“®
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

	//•Ç‚É‚Ô‚Â‚©‚é
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

	if (PAD_INPUT::OnRelease(XINPUT_BUTTON_A))
	{
		weapon()->Shoot(g_main, location.x + 40 * cosf(angle * (float)M_PI * 2), location.y + 40 * sinf(angle * (float)M_PI * 2), bullet_size, PLAYER_SHOT, angle, TWIN_SHOT);
	}
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
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_LEFT_SHOULDER))
	{
		angle -= 0.001f;
	}
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_RIGHT_SHOULDER))
	{
		angle += 0.001f;
	}
}

void Player::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0x00ff00, true);
	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_A))
	{
		DrawCircle(location.x + 40 * cosf(angle * (float)M_PI * 2), location.y + 40 * sinf(angle * (float)M_PI * 2), bullet_size, 0xffff00, true);
	}
	DrawLine(location.x, location.y, location.x + 100 * cosf(angle * (float)M_PI * 2), location.y + 100 * sinf(angle * (float)M_PI * 2),0x00ff00);
}

void Player::Hit()
{
	location.x = 100;
	location.y = 100;
}
