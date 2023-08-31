#pragma once
#include "SceneBase.h"
#include "Title.h"

class GameClear :
    public SceneBase
{
private:
    int score;  //���_�i�[
    int time;   //���Ԋi�[
public:

    //�R���X�g���N�^
    GameClear(int _score,int _time);

    //�f�X�g���N�^
    ~GameClear();

    //�`��ȊO�̍X�V
    SceneBase* Update()override;

    //�`��̍X�V
    void Draw()const override;

};