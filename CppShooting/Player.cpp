#include"Dxlib.h"
#include"Define.h"
#include"Player.h"
#include"PadInput.h"

#define PLAYER_MOVE_SPEED (15000-(speed*1000))

Player::Player()
{
	score = 0;
	speed = 1;
	location.x = 100;
	location.y = 100;
	location.radius = 25;
}
Player::~Player()
{

}
void Player::Update()
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
}

void Player::Draw()const
{
	DrawCircle(location.x, location.y, location.radius, 0x00ff00, true);
}

void Player::Hit()
{

}