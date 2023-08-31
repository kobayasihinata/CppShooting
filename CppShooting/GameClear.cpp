#include "Define.h"
#include "PadInput.h"
#include "GameClear.h"
#include "Title.h"
#include "InputRankingScene.h"

GameClear::GameClear(int _score, int _time)
{
	score = _score;
	time = _time;
}

GameClear::~GameClear()
{

}

SceneBase* GameClear::Update()
{
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return new InputRankingScene(score);
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
