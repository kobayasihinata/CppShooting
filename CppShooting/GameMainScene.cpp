#include"GameMainScene.h"
#include"WeaponPickScene.h"
#include"Title.h"
#include"GameClear.h"
#include"GameOver.h"

GameMainScene::GameMainScene(int w_type)
{
	time = 0;
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
	enemy_countdown = 0;
	boss_flg = false;
	clear_flg = false;
	over_flg = false;
	wait_time = 0;
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
	//かかった時間の測定
	time++;
	//プレイヤーの更新
	player->Update(this);
	//敵の更新
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (enemy[i] != NULL)
		{
			enemy[i]->Update(this);
			if (enemy[i]->GetLocation().x < -50 || enemy[i]->GetLocation().y > SCREEN_HEIGHT + 100 || enemy[i]->GetLocation().y <-100)
			{
				enemy[i] = NULL;
			}
		}
	}
	//弾の更新
	for (int i = 0; i < MAX_BULLET; i++)
	{
		if (bullet[i] != NULL)
		{
			bullet[i]->Update(player->GetLocation().x, player->GetLocation().y);
			if (bullet[i]->GetLocation().x > SCREEN_WIDTH+200 || bullet[i]->GetLocation().x < 0 || bullet[i]->GetLocation().y < -100 || bullet[i]->GetLocation().y > SCREEN_HEIGHT + 100 || bullet[i]->GetDeleteTime() <= 0)
			{
				bullet[i] = NULL;
			}
		}
	}
	//当たり判定
	HitCheck();
	//クリア判定
	if (clear_flg == true)
	{
		return new GameClear(player->GetScore(),time);
	}
	//ゲームオーバー判定
	if (over_flg == true)
	{
		return new GameOver();
	}
	//敵をスポーンさせる処理
	if (--enemy_spawn_int <= 0)
	{
		enemy_spawn_int = 75;
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			if (enemy[i] == NULL)
			{
				if (enemy_countdown > 0)
				{
					enemy[i] = new Enemy(GetRand(100) + 1200, GetRand(600) + 50,false,false);
					--enemy_countdown;
				}
				else
				{
					if (boss_flg == false)
					{
						enemy[i] = new Enemy(1800, 360, true, false);
						boss_flg = true;
					}
					else
					{
						enemy[i] = new Enemy(1800, 360, false, true);
						enemy_spawn_int = 750;
					}
				}
				break;
			}
		}
	}
	//プレイヤーの死亡演出
	if (player->GetHp() <= 0)
	{
		if (++wait_time > 120)
		{
			over_flg = true;
		}
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
	SetFontSize(32);
	DrawFormatString(0, 20, 0xffffff, "残り敵数:%d", enemy_countdown);
	DrawFormatString(0, 60, 0xffffff, "経過時間:%02d:%02d", time / 60, time % 60);
	SetFontSize(16);
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
						if (enemy[j]->Hit(bullet[i]->GetDamage()) <= 0)
						{
							if (enemy[j]->BossFlg() == false)
							{
								player->AddScore(100);
								enemy[j] = NULL;
							}
							else
							{
								player->AddScore(2000);
								clear_flg = true;
							}
						}
						if (bullet[i]->GetHitCount() <= 0)
						{
							bullet[i] = NULL;
						}
						break;
					}
				}
			}
		}
		//プレイヤーと弾の判定
		if (bullet[i] != NULL)
		{
			if (bullet[i]->CheckCollision(player) == true && bullet[i]->GetBulletType() == ENEMY_SHOT && player->GetHp() > 0)
			{
				bullet[i] = NULL;
				player->Hit(1);
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
				player->Hit(1);
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
