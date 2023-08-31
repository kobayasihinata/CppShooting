#include "Define.h"
#include "PadInput.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear(int score, int time)
{

}

GameClear::~GameClear()
{

}

SceneBase* GameClear::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{

	}
	return this;
}


void GameClear::Draw()const
{
	SetFontSize(84);
	DrawString(430, 230, "GameClear!!", 0xffffff);
	SetFontSize(32);
	DrawString(440, 530, "Aƒ{ƒ^ƒ“‚ÅŽŸ‚Ö", 0xffffff);
}
