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
	player->SetWeaponType(pick_cursor + 1);
	return this;
}


void WeaponPickScene::Draw()const
{
	DrawString(0, 0, "WeaponPickScene", 0xffff00);
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
	for (int i = 0; i < 5; i++)
	{
		DrawBox(950, 50+(i*120), SCREEN_WIDTH-40, 150 + (i * 120), 0xffffff, false);
	}
	//DrawTriangle(240, 255 + pick_cursor * 52, 260, 270 + pick_cursor * 52, 240, 285 + pick_cursor * 52, 0xff0000, TRUE);
	DrawTriangle(910, 55 + pick_cursor * 120, 950, 95 + pick_cursor * 120, 910, 135 + pick_cursor * 120, 0xff0000, TRUE);
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