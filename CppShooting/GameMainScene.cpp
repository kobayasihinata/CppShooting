#include"GameMainScene.h"
#include"WeaponPickScene.h"

GameMainScene::GameMainScene(int w_type)
{
	player = new Player(w_type);
	for (int i = 0; i < MAX_ENEMY; i++)
	{
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
			bullet[i]->Update(player->GetLocation().x,player->GetLocation().y);
			if (bullet[i]->GetLocation().x > SCREEN_WIDTH || bullet[i]->GetLocation().x < 0 || bullet[i]->GetLocation().y < -100 || bullet[i]->GetLocation().y > SCREEN_HEIGHT + 100 || bullet[i]->GetDeleteTime() <= 0)
			{
				bullet[i] = NULL;
			}
		}
	}
	HitCheck();

	if (++enemy_spawn_int>200)
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
	//実験用
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new WeaponPickScene();
	}
	return this;
}


void GameMainScene::Draw()const
{
	//if (bullet[0] != NULL)
	//{
	//	DrawFormatString(0, 20, 0xffffff, "angle:%f", bullet[0]->GetAngle());
	//}

	DrawString(0, 0, "GameMain", 0xffff00);
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
		{
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
					//弾と敵の判定
					if (bullet[i]->CheckCollision(enemy[j]) == true && bullet[i]->GetBulletType() != ENEMY_SHOT)
					{
						if (bullet[i]->GetHitCount() <= 0)
						{
							bullet[i] = NULL;
						}
						enemy[j] = NULL;
						break;
					}
				}
			}
		}
		//プレイヤーと弾の判定
		if (bullet[i] != NULL)
		{
			if (bullet[i]->CheckCollision(player) == true && bullet[i]->GetBulletType() == ENEMY_SHOT)
			{
				bullet[i] = NULL;
				player->Hit();
			}
		}
	}
	//敵とプレイヤーの判定
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

void GameMainScene::SpawnBullet(BulletData b_data)
{
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] == NULL)
		{
			bullet[i] = new Bullet(b_data);
			break;
		}
	}
}