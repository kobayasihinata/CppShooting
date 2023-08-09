#include"GameMainScene.h"

GameMainScene::GameMainScene()
{
	player = new Player();
	enemy = new Enemy();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet[i] = NULL;
	}
}

GameMainScene::~GameMainScene()
{
	delete player;
	delete enemy;
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
	}
}

SceneBase* GameMainScene::Update()
{
	player->Update();
	enemy->Update();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] != NULL)
		{
			bullet[i]->Update();
			if (bullet[i]->GetLocation().x > SCREEN_WIDTH)
			{
				bullet[i] = NULL;
			}
		}
	}
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		SpawnBullet(player->GetLocation().x, player->GetLocation().y, 10);
	}
	HitCheck();

	return this;
}


void GameMainScene::Draw()const
{
	DrawString(0, 0, "GameMain", 0xffff00);
	if (player->CheckCollision(enemy) == true)
	{
		DrawString(0, 20, "hit", 0xffff00);
	}
	player->Draw();
	enemy->Draw();
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] != NULL)
		{
			bullet[i]->Draw();
		}
	}
}

void GameMainScene::HitCheck()
{

}

void GameMainScene::SpawnBullet(int x, int y, int radius)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(x,y,radius);
			break;
		}
	}
}