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
	//カーソルを上移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) || (PAD_INPUT::GetLStick().ThumbY > 10000 && y_once == TRUE)) {

		//連続入力しないようにする
		y_once = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//カーソルがはみ出ないように調整する
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

	//カーソルを下移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) || (PAD_INPUT::GetLStick().ThumbY < -10000 && y_once == TRUE)) {

		//連続入力しないようにする
		y_once = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//カーソルがはみ出ないように調整する
		if (++cursor_point.y > 3 && cursor_point.x == 10 || cursor_point.y > 4) {
			cursor_point.y = 0;
		}
		if (cursor_point.y > 3 && cursor_point.x == 12) {
			cursor_point.x = 11;
		}

	}

	//カーソルを右移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) || (PAD_INPUT::GetLStick().ThumbX > 10000 && x_once == TRUE)) {

		//連続入力しないようにする
		x_once = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//カーソルがはみ出ないように調整する
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

	//カーソルを左移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT) || (PAD_INPUT::GetLStick().ThumbX < -10000 && x_once == TRUE)) {

		//連続入力しないようにする
		x_once = FALSE;

		//カーソルがはみ出ないように調整する
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

	//Aボタンが押されたら
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {

		//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);

		//確定ボタンが押された時
		if (cursor_point.x == 11 && cursor_point.y == 4)
		{
			//名前が1文字でも入力されていたら
			if (name.size() > 0)
			{
				//ランキングを更新する
				Ranking::Insert(score, time,const_cast<char*>(name.c_str()));

				//ランキングを描画する
				//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
				return new DrawRanking;
			}
		}
		//名前が9文字以上入力されていないなら
		else if (name.size() < NAME_MAX - 1)
		{
			//名前を入力する
			name += keyboard[cursor_point.y][cursor_point.x];
		}
	}

	//Bボタンが押されて名前が1文字以上入力されているなら
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B) && name.size() > 0) {
		//名前を1文字消す
		//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
		name.erase(name.begin() + (name.size() - 1));
	}

	//1文字以上入力されていてStartボタンが押されたなら
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START) && name.size() > 0)
	{
		//ランキングを更新する
		Ranking::Insert(score,time,const_cast<char*>(name.c_str()));

		//ランキングを描画する
		return new DrawRanking;
	}

	//LスティックのX座標が元の位置に戻ったらフラグをリセットする
	if (PAD_INPUT::GetLStick().ThumbX < 10000 && PAD_INPUT::GetLStick().ThumbX > -10000 && x_once == FALSE) {
		x_once = TRUE;
	}
	//LスティックのY座標が元の位置に戻ったらフラグをリセットする
	if (PAD_INPUT::GetLStick().ThumbY < 10000 && PAD_INPUT::GetLStick().ThumbY > -10000 && y_once == FALSE) {
		y_once = TRUE;
	}
	return this;
}

void InputRankingScene::Draw() const {

	SetFontSize(64);
	DrawString(400, 100, "名前入力", 0xffffff);

	SetFontSize(32);
	DrawBox(420, 250, 665, 280, 0xffffff, TRUE);
	DrawFormatString(440, 250, 0x000000, "%s", name.c_str());

	//確定のカーソルだけ大きくする
	if (cursor_point.x == 11 && cursor_point.y == 4)
	{
		DrawBox(308 + 40 * cursor_point.x, 355 + 40 * cursor_point.y,
			388 + 40 * cursor_point.x, 385 + 40 * cursor_point.y, 0xffffff, TRUE);
		//”確定”の文字色を変える
		DrawString(770, 513, "OK", 0x000000);
	}
	else
	{
		DrawBox(308 + 40 * cursor_point.x, 355 + 40 * cursor_point.y,
			338 + 40 * cursor_point.x, 385 + 40 * cursor_point.y, 0xffffff, TRUE);
		//普通の文字色の”確定”を描画する
		DrawString(770, 513, "OK", 0xffffff);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 14; j++) {
			if (j == cursor_point.x && i == cursor_point.y) {
				//I、i、Lの文字の空白を調整する
				if (i == 0 && j == 8 && keyboard[0][8] || i == 2 && j == 8 && keyboard[2][8] || i == 2 && j == 11 && keyboard[2][11]) {
					DrawFormatString(j * 40 + 318, i * 40 + 355, 0x000000,"%c", keyboard[i][j]);
				}
				//gの文字高さを調整する
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
				//I、i、Lの文字の空白を調整する
				if (i == 0 && j == 8 && keyboard[0][8] || i == 2 && j == 8 && keyboard[2][8] || i == 2 && j == 11 && keyboard[2][11]) {
					DrawFormatString(j * 40 + 318, i * 40 + 355, 0xffffff, "%c", keyboard[i][j]);
				}
				//gの文字高さを調整する
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
	DrawString(100, 840, "STARTボタン or OKで確定", 0xffffff);
}
