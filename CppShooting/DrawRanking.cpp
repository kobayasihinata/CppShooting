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
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A))
	{
		return new Title();
	}
	return this;
}

void DrawRanking::Draw() const
{

	int color = 0xffffff;
	for (int i = 0; i < RANK; i++)
	{
		//���ʂɉ����ĕ����F��ς���
		switch (Ranking::GetData(i).no)
		{
		case 1:
			color = 0xc0c0c0;
			break;
		case 2:
		case 3:
		case 4:
		case 5:
			color = 0x000000;
			break;
		default:
			break;
		}
		DrawFormatString(270, 220 + (70 * i), color,"%d��", Ranking::GetData(i).no);
		DrawFormatString(400, 220 + (70 * i), color,"%.10s", Ranking::GetData(i).name);
		DrawFormatString(950, 220 + (70 * i), color,"%6dpt", Ranking::GetData(i).score);
	}

	DrawString(425, 650, "A �Ń^�C�g��", 0xff0000, true);
}
