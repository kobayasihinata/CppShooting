#include "DxLib.h"
#include "GameMainScene.h"
#include "PadInput.h"
#include "Title.h"
#include "Ranking.h"

#define FADE_TIME 300
#define RANKING_DATE 5

#define FILEPATH "txt/rankingdata.txt"

RankingData Ranking::Data[RANK];

void Ranking::Insert(int _score, int _time, char name[NAME_MAX])
{
	ReadRanking();
	if (Data[RANK - 1].score < _score || (Data[RANK - 1].score == _score && Data[RANK - 1].time > _time))
	{
		Data[RANK - 1].score = _score;
		Data[RANK - 1].time = _time;
		for (int i = 0; i < NAME_MAX; i++)
		{
			Data[RANK - 1].name[i] = name[i];
		}
		SortRanking();
		SaveRanking();
	}
}

void Ranking::SortRanking()
{
	RankingData work;	//���ёւ��p�̕ϐ�

	// �I��@�\�[�g
	for (int i = 0; i < RANK - 1; i++) {
		for (int j = i + 1; j < RANK; j++) {
			if (Data[i].score < Data[j].score) {
				work = Data[i];
				Data[i] = Data[j];
				Data[j] = work;
			}
			if (Data[i].score == Data[j].score && Data[i].time > Data[j].time) {
				work = Data[i];
				Data[i] = Data[j];
				Data[j] = work;
			}
		}
	}

	// ���ʕt��
	for (int i = 0; i < RANK; i++) {
		Data[i].no = 1;
	}

	// ���_�������ꍇ�́A�������ʂƂ���
	// �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
	for (int i = 0; i < RANK - 1; i++) {
		for (int j = i + 1; j < RANK; j++) {
			if (Data[i].score > Data[j].score || (Data[i].score == Data[j].score && Data[i].time < Data[j].time)) {
				Data[j].no++;
			}
		}
	}
}

void Ranking::SaveRanking(void) {
	FILE* fp = NULL;

	//�t�@�C���I�[�v��
	if (fopen_s(&fp, FILEPATH, "w") != NULL)
	{
		throw FILEPATH;
	}

	//�����L���O�f�[�^����������
	for (int i = 0; i < RANK; i++) {
		fprintf_s(fp, "%1d%10d%10d%10s\n", Data[i].no, Data[i].score, Data[i].time,Data[i].name);
	}

	fclose(fp);
}

void Ranking::ReadRanking(void) {
	FILE* fp = NULL;

	//�t�@�C���I�[�v��
	if (fopen_s(&fp, FILEPATH, "r") != NULL)
	{
		throw FILEPATH;
	}

	//�����L���O�f�[�^�z����f�[�^��ǂݍ���
	for (int i = 0; i < RANK; i++) {
		fscanf_s(fp, "%1d%10d%10d%10s", &Data[i].no, &Data[i].score, &Data[i].time, Data[i].name, NAME_MAX);
	}

	//�t�@�C���N���[�Y
	fclose(fp);
}
