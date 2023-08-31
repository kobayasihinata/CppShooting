#include "DrawRanking.h"
#include "Ranking.h"
#include "PadInput.h"
#include "Title.h"

DrawRanking::DrawRanking()
{
	//�����L���O�f�[�^�̓ǂݍ���
	Ranking::ReadRanking();
}

DrawRanking::~DrawRanking()
{
}

SceneBase* DrawRanking::Update()
{
	//A�{�^���Ń^�C�g����
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B))
	{
		return new Title();
	}
	return this;
}

void DrawRanking::Draw() const
{
	SetFontSize(32);
	int color = 0xffffff;
	for (int i = 0; i < RANK; i++)
	{
		//���ʂɉ����ĕ����F��ς���
		switch (Ranking::GetData(i).no)
		{
		case 1:
			color = 0xffff00;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			color = 0xffffff;
			break;
		default:
			break;
		}
		DrawFormatString(270, 170 + (70 * i), color,"%d��", Ranking::GetData(i).no);
		DrawFormatString(400, 170 + (70 * i), color,"%.10s", Ranking::GetData(i).name);
		DrawFormatString(550, 170 + (70 * i), color,"%6dpt", Ranking::GetData(i).score);
		DrawFormatString(850, 170 + (70 * i), color, "time %02d:%02d", Ranking::GetData(i).time / 60, Ranking::GetData(i).time % 60);
	}

	DrawString(425, 650, "B �Ń^�C�g��", 0xff0000, true);
}
