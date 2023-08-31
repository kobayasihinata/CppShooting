#include "Define.h"
#include "PadInput.h"
#include "GameClear.h"
#include "Title.h"
#include "InputRankingScene.h"
#include "DrawRanking.h"

GameClear::GameClear(int _score, int _time)
{
	count = 0;
	score = _score;
	time = _time;
	Ranking::ReadRanking();
}

GameClear::~GameClear()
{

}

SceneBase* GameClear::Update()
{
	if (++count >= 60 && PAD_INPUT::OnButton(XINPUT_BUTTON_A))	//countは連打などによる押しミス防止												
	{
		if (score > Ranking::GetData(RANK - 1).score || (score == Ranking::GetData(RANK - 1).score && time < Ranking::GetData(RANK - 1).time))
		{
			return new InputRankingScene(score,time);
		}
		else
		{
			return new DrawRanking();//ボタンAが押されたらランキング、または名前入力画面に遷移
		}
	}
	return this;
}


void GameClear::Draw()const
{
	SetFontSize(84);
	DrawString(430, 230, "GameClear!!", 0xffffff);
	SetFontSize(32);
	DrawString(440, 530, "Aボタンで次へ", 0xffffff);
}
