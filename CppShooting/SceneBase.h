#pragma once

class SceneBase
{
protected:


public:

	//�`��ȊO�̍X�V
	virtual SceneBase* Update() = 0;

	//�`��̍X�V
	virtual void Draw() const = 0;

};

