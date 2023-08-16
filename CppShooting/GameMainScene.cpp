#include"GameMainScene.h"

Bullet* bullet[MAX_BULLET];

GameMainScene::GameMainScene()
{
	player = new Player();
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		//enemy[i] = new Enemy(1500, GetRand(600) + 50);
		enemy[i] = NULL;
	}
	for (int i = 0; i < MAX_BULLET; i++)
	{
		bullet[i] = NULL;
	}
	enemy_spawn_int = 0;
}

GameMainScene::~GameMainScene()
{
	delete player;
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		delete enemy[i];
	}
	for (int i = 0; i < MAX_BULLET; i++)
	{
		delete bullet[i];
	}
}

SceneBase* GameMainScene::Update()
{
	player->Update(this);
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
		{
			enemy[i]->Update(this);
			if (enemy[i]->GetLocation().x < -50)
			{
				enemy[i] = NULL;
			}
		}
	}
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] != NULL)
		{
			bullet[i]->Update();
			if (bullet[i]->GetLocation().x > SCREEN_WIDTH || bullet[i]->GetLocation().x < 0 || bullet[i]->GetLocation().y < 0 || bullet[i]->GetLocation().y > SCREEN_HEIGHT)
			{
				bullet[i] = NULL;
			}
		}
	}
	HitCheck();

	if (++enemy_spawn_int>100)
	{
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			if (enemy[i] == NULL)
			{
				enemy[i] = new Enemy(GetRand(100)+1200,GetRand(600)+50);
				break;
			}
		}
		enemy_spawn_int = 0;
	}

	return this;
}


void GameMainScene::Draw()const
{
	DrawString(0, 0, "GameMain", 0xffff00);
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
		{
			if (player->CheckCollision(enemy[i]) == true)
			{
				DrawString(0, 20, "hit", 0xffff00);
			}
			enemy[i]->Draw();
		}
	}
	player->Draw();
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
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] != NULL)
		{
			for (int j = 0; j < MAX_ENEMY; j++)
			{
				if (enemy[j] != NULL)
				{
					//íeÇ∆ìGÇÃîªíË
					if (bullet[i]->CheckCollision(enemy[j]) == true && bullet[i]->GetBulletType() == 0)
					{
						bullet[i] = NULL;
						enemy[j] = NULL;
						break;
					}
				}
			}
		}
		//ÉvÉåÉCÉÑÅ[Ç∆íeÇÃîªíË
		if (bullet[i] != NULL)
		{
			if (bullet[i]->CheckCollision(player) == true && bullet[i]->GetBulletType() == 1)
			{
				bullet[i] = NULL;
				player->Hit();
			}
		}
	}
	//ìGÇ∆ÉvÉåÉCÉÑÅ[ÇÃîªíË
	for (int j = 0; j < MAX_ENEMY; j++)
	{
		if (enemy[j] != NULL)
		{
			if (enemy[j]->CheckCollision(player) == true)
			{
				player->Hit();
			}
		}
	}
}

void GameMainScene::SpawnBullet(int x, int y, int radius,int type)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(x,y,radius,type);
			break;
		}
	}
}