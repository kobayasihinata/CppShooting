#pragma once
#include "SceneBase.h"
#include "GameMainScene.h"

#define TITLEMODESELECT_X 780
#define TITLEMODESELECT_Y 300

class Title :
    public SceneBase
{
private:
    int cursor_y;   //�J�[�\����Y���W
    int cursor_num; //�J�[�\���̔ԍ�
    int s_interval; //�X�e�B�b�N�̓��͊Ԋu
    int b_interval; //�{�^���̓��͊Ԋu
    int cursor_anim;//�J�[�\���̃A�j���[�V�����p
public:

    //�R���X�g���N�^
    Title();

    //�f�X�g���N�^
    ~Title();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};




