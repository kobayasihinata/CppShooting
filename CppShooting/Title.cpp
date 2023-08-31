#include"Define.h"
#include"PadInput.h"
#include"Title.h"
#include"WeaponPickScene.h"
#include "DrawRanking.h"

#define _USE_MATH_DEFINES
#include <math.h>

Title::Title()
{
	cursor_num = 0;
	cursor_y = 0;
	s_interval = 0;
	b_interval = 0;
	cursor_anim = 40;
}

Title::~Title()
{
	
}

SceneBase* Title::Update()
{
	cursor_y = cursor_num * 80;
	if (s_interval < 30) {
		s_interval++;
	}
	if (b_interval < 30) {
		b_interval++;
	}

	if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_UP))
	{
		if (b_interval >= 20)
		{
			cursor_num--;
			b_interval = 0;
		}
	}
	else if (PAD_INPUT::OnPressed(XINPUT_BUTTON_DPAD_DOWN))
	{
		if (b_interval >= 20)
		{
			cursor_num++;
			b_interval = 0;
		}
	}
	else
	{
		b_interval = 20;
	}
	if (PAD_INPUT::GetLStick().ThumbY > MARGIN) {
		if (s_interval >= 20)
		{
			cursor_num--;
			s_interval = 0;
		}
	}
	else if (PAD_INPUT::GetLStick().ThumbY < -MARGIN) {
		if (s_interval >= 20)
		{
			cursor_num++;
			s_interval = 0;
		}
	}
	else
	{
		s_interval = 20;
	}

	if (cursor_num < 0)cursor_num = 3;
	if (cursor_num > 3)cursor_num = 0;

	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		switch (cursor_num)
		{
		case 0:
			return new WeaponPickScene();
			break;
		case 1:
			return new DrawRanking();
			break;
		case 3:
			return nullptr;
			break;
		}
	}
	cursor_anim -= 2;
	if (cursor_anim< -40)
	{
		cursor_anim = 40;
	}
	return this;
}


void Title::Draw()const
{
	SetFontSize(84);
	DrawString(430, 30, "C++Shooting", 0xffffff);
	SetFontSize(64);
	DrawTriangle(430, 240 + cursor_y +abs(cursor_anim), 500, 280 + cursor_y, 430, 320 + cursor_y - abs(cursor_anim), 0xffffff, true);
	DrawString(500, 250, "ゲーム開始", 0xffffff);
	DrawString(500, 330, "ランキング", 0xffffff);
	DrawString(500, 410, "ヘルプ",	   0xffffff);
	DrawString(500, 490, "ゲーム終了", 0xffffff);
	switch (cursor_num)
	{
	case 0:
		DrawBox(500, 250, 830, 320, 0xffffff, true);
		DrawString(500, 250, "ゲーム開始", 0x000000);
		break;
	case 1:
		DrawBox(500, 330, 830, 400, 0xffffff, true);
		DrawString(500, 330, "ランキング", 0x000000);
		break;
	case 2:
		DrawBox(500, 410, 700, 480, 0xffffff, true);
		DrawString(500, 410, "ヘルプ", 0x000000);
		break;
	case 3:
		DrawBox(500, 490, 830, 570, 0xffffff, true);
		DrawString(500, 490, "ゲーム終了", 0x000000);
		break;
	}
}
