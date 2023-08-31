#pragma once
#include "SceneBase.h"

class GameOver :
    public SceneBase
{
private:
    int count;  //�{�^�����͊Ԋu
    int score;  //���_�i�[
    int time;   //���Ԋi�[
public:

    //�R���X�g���N�^
    GameOver(int _score, int _time);

    //�f�X�g���N�^
    ~GameOver();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};