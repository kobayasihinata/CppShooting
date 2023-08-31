#include "Define.h"
#include "PadInput.h"
#include "GameOver.h"
#include "Title.h"
#include "InputRankingScene.h"
#include "DrawRanking.h"

GameOver::GameOver(int _score, int _time)
{
	count = 0;
	score = _score;
	time = _time;
	Ranking::ReadRanking();
}

GameOver::~GameOver()
{

}

SceneBase* GameOver::Update()
{
	if (++count >= 60 && PAD_INPUT::OnButton(XINPUT_BUTTON_A))	//count�͘A�łȂǂɂ�鉟���~�X�h�~												
	{
		if (score > Ranking::GetData(RANK - 1).score || (score == Ranking::GetData(RANK - 1).score && time < Ranking::GetData(RANK - 1).time))
		{
			return new InputRankingScene(score, time);
		}
		else
		{
			return new DrawRanking();//�{�^��A�������ꂽ�烉���L���O�A�܂��͖��O���͉�ʂɑJ��
		}
	}
	return this;
}


void GameOver::Draw()const
{
	SetFontSize(84);
	DrawString(430, 230, "GameOver", 0xffffff);
	SetFontSize(32);
	DrawString(440, 530, "A�{�^���Ŏ���", 0xffffff);
}
