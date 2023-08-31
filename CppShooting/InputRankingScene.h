#pragma once
#include "SceneBase.h"
#include "Ranking.h"
#include "DxLib.h"
#include "PadInput.h"
#include<string>

class InputRankingScene : public SceneBase
{
private:
	Ranking ranking;

	int time;	//�N���A�^�C���i�[�p
	int score;	//�X�R�A�i�[�p
	bool x_once;	//L�X�e�B�b�N���͏d���h�~�p�i���j
	bool y_once;	//L�X�e�B�b�N���͏d���h�~�p�i�c�j

	std::string name;	//���O���͗p

	POINT cursor_point;	//�J�[�\���̍��W�p

	//���͉\�����i�[
	const char keyboard[5][14] = { "ABCDEFGHIJKLM" ,"NOPQRSTUVWXYZ" ,"abcdefghijklm" ,"nopqrstuvwxyz" ,"0123456789" };

public:

	//�R���X�g���N�^
	InputRankingScene(int score,int _time);

	//�f�X�g���N�^
	~InputRankingScene();

	//�`��ȊO�̍X�V�����s
	SceneBase* Update()override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw()const override;
};



