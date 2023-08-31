#include "InputRankingScene.h"
#include "DrawRanking.h"
#include "PadInput.h"
#include <DxLib.h>

InputRankingScene::InputRankingScene(int _score,int _time)
{
	score = _score;
	time = _time;
	x_once = TRUE;
	y_once = TRUE;
	cursor_point = { 0, 0 };
	ranking.ReadRanking();
}

InputRankingScene::~InputRankingScene()
{

}

SceneBase* InputRankingScene::Update()
{
	//�J�[�\������ړ�������
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) || (PAD_INPUT::GetLStick().ThumbY > 10000 && y_once == TRUE)) {

		//�A�����͂��Ȃ��悤�ɂ���
		y_once = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//�J�[�\�����͂ݏo�Ȃ��悤�ɒ�������
		if (--cursor_point.y < 0) {
			if (cursor_point.x == 10) {
				cursor_point.y = 3;
			}
			else {
				cursor_point.y = 4;
			}
			if (cursor_point.x == 12) {
				cursor_point.x = 11;
			}
		}
	}

	//�J�[�\�������ړ�������
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) || (PAD_INPUT::GetLStick().ThumbY < -10000 && y_once == TRUE)) {

		//�A�����͂��Ȃ��悤�ɂ���
		y_once = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//�J�[�\�����͂ݏo�Ȃ��悤�ɒ�������
		if (++cursor_point.y > 3 && cursor_point.x == 10 || cursor_point.y > 4) {
			cursor_point.y = 0;
		}
		if (cursor_point.y > 3 && cursor_point.x == 12) {
			cursor_point.x = 11;
		}

	}

	//�J�[�\�����E�ړ�������
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) || (PAD_INPUT::GetLStick().ThumbX > 10000 && x_once == TRUE)) {

		//�A�����͂��Ȃ��悤�ɂ���
		x_once = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//�J�[�\�����͂ݏo�Ȃ��悤�ɒ�������
		if (++cursor_point.x == 10 && cursor_point.y > 3)
		{
			cursor_point.x = 11;
		}
		if (cursor_point.x > 11 && cursor_point.y == 4) {
			cursor_point.x = 0;
		}
		if (cursor_point.x > 12) {
			cursor_point.x = 0;
		}
	}

	//�J�[�\�������ړ�������
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT) || (PAD_INPUT::GetLStick().ThumbX < -10000 && x_once == TRUE)) {

		//�A�����͂��Ȃ��悤�ɂ���
		x_once = FALSE;

		//�J�[�\�����͂ݏo�Ȃ��悤�ɒ�������
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
		if (--cursor_point.x < 0) {
			if (cursor_point.y > 3) {
				cursor_point.x = 11;
			}
			else {
				cursor_point.x = 12;
			}
		}
		if (cursor_point.x == 10 && cursor_point.y == 4)
		{
			cursor_point.x = 9;
		}
	}

	//A�{�^���������ꂽ��
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {

		//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);

		//�m��{�^���������ꂽ��
		if (cursor_point.x == 11 && cursor_point.y == 4)
		{
			//���O��1�����ł����͂���Ă�����
			if (name.size() > 0)
			{
				//�����L���O���X�V����
				Ranking::Insert(score, time,const_cast<char*>(name.c_str()));

				//�����L���O��`�悷��
				//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
				return new DrawRanking;
			}
		}
		//���O��9�����ȏ���͂���Ă��Ȃ��Ȃ�
		else if (name.size() < NAME_MAX - 1)
		{
			//���O����͂���
			name += keyboard[cursor_point.y][cursor_point.x];
		}
	}

	//B�{�^����������Ė��O��1�����ȏ���͂���Ă���Ȃ�
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B) && name.size() > 0) {
		//���O��1��������
		//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
		name.erase(name.begin() + (name.size() - 1));
	}

	//1�����ȏ���͂���Ă���Start�{�^���������ꂽ�Ȃ�
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START) && name.size() > 0)
	{
		//�����L���O���X�V����
		Ranking::Insert(score,time,const_cast<char*>(name.c_str()));

		//�����L���O��`�悷��
		return new DrawRanking;
	}

	//L�X�e�B�b�N��X���W�����̈ʒu�ɖ߂�����t���O�����Z�b�g����
	if (PAD_INPUT::GetLStick().ThumbX < 10000 && PAD_INPUT::GetLStick().ThumbX > -10000 && x_once == FALSE) {
		x_once = TRUE;
	}
	//L�X�e�B�b�N��Y���W�����̈ʒu�ɖ߂�����t���O�����Z�b�g����
	if (PAD_INPUT::GetLStick().ThumbY < 10000 && PAD_INPUT::GetLStick().ThumbY > -10000 && y_once == FALSE) {
		y_once = TRUE;
	}
	return this;
}

void InputRankingScene::Draw() const {

	SetFontSize(64);
	DrawString(400, 100, "���O����", 0xffffff);

	SetFontSize(32);
	DrawBox(420, 250, 665, 280, 0xffffff, TRUE);
	DrawFormatString(440, 250, 0x000000, "%s", name.c_str());

	//�m��̃J�[�\�������傫������
	if (cursor_point.x == 11 && cursor_point.y == 4)
	{
		DrawBox(308 + 40 * cursor_point.x, 355 + 40 * cursor_point.y,
			388 + 40 * cursor_point.x, 385 + 40 * cursor_point.y, 0xffffff, TRUE);
		//�h�m��h�̕����F��ς���
		DrawString(770, 513, "OK", 0x000000);
	}
	else
	{
		DrawBox(308 + 40 * cursor_point.x, 355 + 40 * cursor_point.y,
			338 + 40 * cursor_point.x, 385 + 40 * cursor_point.y, 0xffffff, TRUE);
		//���ʂ̕����F�́h�m��h��`�悷��
		DrawString(770, 513, "OK", 0xffffff);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 14; j++) {
			if (j == cursor_point.x && i == cursor_point.y) {
				//I�Ai�AL�̕����̋󔒂𒲐�����
				if (i == 0 && j == 8 && keyboard[0][8] || i == 2 && j == 8 && keyboard[2][8] || i == 2 && j == 11 && keyboard[2][11]) {
					DrawFormatString(j * 40 + 318, i * 40 + 355, 0x000000,"%c", keyboard[i][j]);
				}
				//g�̕��������𒲐�����
				else if (i == 2 && j == 6 && keyboard[0][8]) {
					DrawFormatString(j * 40 + 318, i * 40 + 348, 0x000000, "%c", keyboard[i][j]);
				}
				else
				{
					DrawFormatString(j * 40 + 318, i * 40 + 355, 0x000000, "%c", keyboard[i][j]);
				}
			}
			else
			{
				//I�Ai�AL�̕����̋󔒂𒲐�����
				if (i == 0 && j == 8 && keyboard[0][8] || i == 2 && j == 8 && keyboard[2][8] || i == 2 && j == 11 && keyboard[2][11]) {
					DrawFormatString(j * 40 + 318, i * 40 + 355, 0xffffff, "%c", keyboard[i][j]);
				}
				//g�̕��������𒲐�����
				else if (i == 2 && j == 6 && keyboard[0][8]) {
					DrawFormatString(j * 40 + 318, i * 40 + 348, 0xffffff,"%c", keyboard[i][j]);
				}
				else
				{
					DrawFormatString(j * 40 + 318, i * 40 + 355, 0xffffff, "%c", keyboard[i][j]);
				}

			}

		}
	}
	DrawString(100, 840, "START�{�^�� or OK�Ŋm��", 0xffffff);
}
