#pragma once
#include "SceneBase.h"

class DrawRanking :
	public SceneBase
{
private:

public:
	//�R���X�g���N�^
	DrawRanking();

	//�f�X�g���N�^
	~DrawRanking();

	//�`��ȊO�̍X�V�����s
	SceneBase* Update() override;

	//�`��Ɋւ��邱�Ƃ�����
	void Draw() const override;
};



