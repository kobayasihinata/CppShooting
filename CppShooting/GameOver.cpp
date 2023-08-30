#include "Define.h"
#include "PadInput.h"
#include "GameOver.h"
#include "Title.h"

GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

SceneBase* GameOver::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{

	}
	return this;
}


void GameOver::Draw()const
{

}
