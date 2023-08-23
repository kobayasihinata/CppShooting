#include"WeaponPickScene.h"

WeaponPickScene::WeaponPickScene()
{
	pick_cursor = 0;
	now_current = 0;
	player = new Player();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet[i] = NULL;
	}
	move_span = 0;
	try_flg = false;
	enter_flg = false;
}

WeaponPickScene::~WeaponPickScene()
{
	delete player;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
	}
}

SceneBase* WeaponPickScene::Update()
{
	if (enter_flg == false)
	{
		if (try_flg == true)
		{
			player->Update(this);
			for (int i = 0; i < MAX_BULLET; i++)
			{
				if (bullet[i] != NULL)
				{
					bullet[i]->Update();
					if (bullet[i]->GetLocation().x > SCREEN_WIDTH || bullet[i]->GetLocation().x < 0 || bullet[i]->GetLocation().y < -100 || bullet[i]->GetLocation().y > SCREEN_HEIGHT + 100)
					{
						bullet[i] = NULL;
					}
				}
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
			{
				try_flg = false;
			}
		}
		else
		{
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN))
			{
				if (++pick_cursor > 4)
				{
					pick_cursor = 0;
				}
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP))
			{
				if (--pick_cursor < 0)
				{
					pick_cursor = 4;
				}
			}
			if (--move_span <= 0 && PAD_INPUT::GetLStick().ThumbY <= -5000)
			{
				move_span = 80;
				if (++pick_cursor > 4)
				{
					pick_cursor = 0;
				}
			}
			if (--move_span <= 0 && PAD_INPUT::GetLStick().ThumbY >= 5000)
			{
				move_span = 80;
				if (--pick_cursor < 0)
				{
					pick_cursor = 4;
				}
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_Y))
			{
				try_flg = true;
				player->SetWeaponType(pick_cursor + 1);
			}
			if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
			{
				enter_flg = true;
			}
		}
	}
	else
	{
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
		{
			enter_flg = false;
		}			
		if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
		{
			enter_flg = false;
		}
	}
	return this;
}


void WeaponPickScene::Draw()const
{
	player->Draw();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] != NULL)
		{
			bullet[i]->Draw();
		}
	}
	DrawBox(880, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x000000, true);
	DrawBox(880, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0xffffff, false);
	DrawBox(0, 520, SCREEN_WIDTH - 400, SCREEN_HEIGHT, 0x000000, true);
	DrawBox(0, 520, SCREEN_WIDTH - 400, SCREEN_HEIGHT, 0xffffff, false);
	SetFontSize(32);
	for (int i = 0; i < 5; i++)
	{
		DrawBox(950, 50+(i*120), SCREEN_WIDTH-40, 150 + (i * 120), 0xffffff, false);
		switch (i)
		{
		case 0:
			DrawString(970, 85 + (i * 120),"SINGLE SHOT",0xffffff);
			break;
		case 1:
			DrawString(970, 85 + (i * 120), "DOUBLE SHOT", 0xffffff);
			break;
		case 2:
			DrawString(970, 85 + (i * 120), "TRIPLE SHOT", 0xffffff);
			break;
		case 3:
			DrawString(970, 85 + (i * 120), "QUAD SHOT", 0xffffff);
			break;
		case 4:
			DrawString(970, 85 + (i * 120), "FIVE SHOT", 0xffffff);
			break;
		}
	}
	SetFontSize(16);
	//DrawTriangle(240, 255 + pick_cursor * 52, 260, 270 + pick_cursor * 52, 240, 285 + pick_cursor * 52, 0xff0000, TRUE);
	DrawTriangle(910, 60 + pick_cursor * 120, 950, 100 + pick_cursor * 120, 910, 140 + pick_cursor * 120, 0xff0000, TRUE);
	if (try_flg == false)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawBox(0, 0, 880, 520, 0x000000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
		DrawBox(881, 1, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, 0x000000, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	if (enter_flg == true)
	{
		DrawBox(340, 240, 940, 480, 0x000000, true);
		DrawBox(340, 240, 940, 480, 0xffffff, false);
	}
}
void WeaponPickScene::SpawnBullet(float x, float y, int radius, float speed, int type, float angle)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(x, y, radius, speed, type, angle);
			break;
		}
	}
}