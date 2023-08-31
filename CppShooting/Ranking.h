#pragma once
#define RANK 5
#define NAME_MAX 10

struct RankingData
{
	int no;
	char name[10];
	int score;
	int time;
};

class Ranking
{
private:

	static RankingData Data[RANK];

	//�����L���O�̕��בւ�
	static void SortRanking();

	//�����L���O�f�[�^�̕ۑ�
	static void SaveRanking();

public:

	//�����L���O�f�[�^�̍X�V
	static void Insert(int _score, int _time, char name[NAME_MAX]);

	//�����L���O�f�[�^�ǂݍ���
	static void ReadRanking();

	//�����L���O�̎擾�̎擾
	static RankingData GetData(int n) { return Data[n]; }
};



