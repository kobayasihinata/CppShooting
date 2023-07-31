#include"GameMainScene.h"

GameMainScene::GameMainScene()
{
	player = new Player();
}

GameMainScene::~GameMainScene()
{
	delete player;
}

SceneBase* GameMainScene::Update()
{
	player->Update();
	return this;
}


void GameMainScene::Draw()const
{
	DrawString(0, 0, "GameMain", 0xffff00);

	player->Draw();
}