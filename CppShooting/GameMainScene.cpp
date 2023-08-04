#include"GameMainScene.h"

GameMainScene::GameMainScene()
{
	player = new Player();
	enemy = new Enemy();
}

GameMainScene::~GameMainScene()
{
	delete player;
	delete enemy;
}

SceneBase* GameMainScene::Update()
{
	player->Update();
	enemy->Update();

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
}

void GameMainScene::HitCheck()
{

}