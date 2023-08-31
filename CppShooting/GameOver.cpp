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
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return new Title();
	}
	return this;
}


void GameOver::Draw()const
{
	SetFontSize(84);
	DrawString(430, 230, "GameOver", 0xffffff);
	SetFontSize(32);
	DrawString(440, 530, "Aボタンでタイトルへ", 0xffffff);
}
