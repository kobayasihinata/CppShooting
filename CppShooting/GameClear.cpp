#include "Define.h"
#include "PadInput.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

SceneBase* GameClear::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START))
	{

	}
	return this;
}


void GameClear::Draw()const
{

}
