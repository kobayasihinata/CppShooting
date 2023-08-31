#include "InputRankingScene.h"
#include "DrawRanking.h"
#include "PadInput.h"
#include <DxLib.h>

InputRankingScene::InputRankingScene(int _score)
{
	Score = _score;
	XOnce = TRUE;
	YOnce = TRUE;
	CursorPoint = { 0, 0 };
	ranking.ReadRanking();
}

InputRankingScene::~InputRankingScene()
{

}

SceneBase* InputRankingScene::Update()
{
	//カーソルを上移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_UP) || (PAD_INPUT::GetLStick().ThumbY > 10000 && YOnce == TRUE)) {

		//連続入力しないようにする
		YOnce = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//カーソルがはみ出ないように調整する
		if (--CursorPoint.y < 0) {
			if (CursorPoint.x == 10) {
				CursorPoint.y = 3;
			}
			else {
				CursorPoint.y = 4;
			}
			if (CursorPoint.x == 12) {
				CursorPoint.x = 11;
			}
		}
	}

	//カーソルを下移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_DOWN) || (PAD_INPUT::GetLStick().ThumbY < -10000 && YOnce == TRUE)) {

		//連続入力しないようにする
		YOnce = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//カーソルがはみ出ないように調整する
		if (++CursorPoint.y > 3 && CursorPoint.x == 10 || CursorPoint.y > 4) {
			CursorPoint.y = 0;
		}
		if (CursorPoint.y > 3 && CursorPoint.x == 12) {
			CursorPoint.x = 11;
		}

	}

	//カーソルを右移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_RIGHT) || (PAD_INPUT::GetLStick().ThumbX > 10000 && XOnce == TRUE)) {

		//連続入力しないようにする
		XOnce = FALSE;

		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);

		//カーソルがはみ出ないように調整する
		if (++CursorPoint.x == 10 && CursorPoint.y > 3)
		{
			CursorPoint.x = 11;
		}
		if (CursorPoint.x > 11 && CursorPoint.y == 4) {
			CursorPoint.x = 0;
		}
		if (CursorPoint.x > 12) {
			CursorPoint.x = 0;
		}
	}

	//カーソルを左移動させる
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_DPAD_LEFT) || (PAD_INPUT::GetLStick().ThumbX < -10000 && XOnce == TRUE)) {

		//連続入力しないようにする
		XOnce = FALSE;

		//カーソルがはみ出ないように調整する
		//PlaySoundMem(SelectSE, DX_PLAYTYPE_BACK);
		if (--CursorPoint.x < 0) {
			if (CursorPoint.y > 3) {
				CursorPoint.x = 11;
			}
			else {
				CursorPoint.x = 12;
			}
		}
		if (CursorPoint.x == 10 && CursorPoint.y == 4)
		{
			CursorPoint.x = 9;
		}
	}

	//Aボタンが押されたら
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_A)) {

		//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);

		//確定ボタンが押された時
		if (CursorPoint.x == 11 && CursorPoint.y == 4)
		{
			//名前が1文字でも入力されていたら
			if (Name.size() > 0)
			{
				//ランキングを更新する
				Ranking::Insert(Score, const_cast<char*>(Name.c_str()));

				//ランキングを描画する
				//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
				return new DrawRanking;
			}
		}
		//名前が9文字以上入力されていないなら
		else if (Name.size() < NAME_MAX - 1)
		{
			//名前を入力する
			Name += KeyBoard[CursorPoint.y][CursorPoint.x];
		}
	}

	//Bボタンが押されて名前が1文字以上入力されているなら
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_B) && Name.size() > 0) {
		//名前を1文字消す
		//PlaySoundMem(DecisionSE, DX_PLAYTYPE_BACK);
		Name.erase(Name.begin() + (Name.size() - 1));
	}

	//1文字以上入力されていてStartボタンが押されたなら
	if (PAD_INPUT::OnButton(XINPUT_BUTTON_START) && Name.size() > 0)
	{
		//ランキングを更新する
		Ranking::Insert(Score, const_cast<char*>(Name.c_str()));

		//ランキングを描画する
		return new DrawRanking;
	}

	//LスティックのX座標が元の位置に戻ったらフラグをリセットする
	if (PAD_INPUT::GetLStick().ThumbX < 10000 && PAD_INPUT::GetLStick().ThumbX > -10000 && XOnce == FALSE) {
		XOnce = TRUE;
	}
	//LスティックのY座標が元の位置に戻ったらフラグをリセットする
	if (PAD_INPUT::GetLStick().ThumbY < 10000 && PAD_INPUT::GetLStick().ThumbY > -10000 && YOnce == FALSE) {
		YOnce = TRUE;
	}
	return this;
}

void InputRankingScene::Draw() const {

	DrawGraph(0, 0, Img, TRUE);

	DrawString(0, 100, "名前入力", 0xffffff);

	DrawBox(315, 240, 1065, 350, 0xffffff, TRUE);
	DrawFormatString(340, 250, 0x000000, "%s", Name.c_str());

	//確定のカーソルだけ大きくする
	if (CursorPoint.x == 11 && CursorPoint.y == 4)
	{
		DrawBox(308 + 85 * CursorPoint.x, 353 + 85 * CursorPoint.y,
			458 + 85 * CursorPoint.x, 440 + 85 * CursorPoint.y, 0x808080, TRUE);
		//”確定”の文字色を変える
		DrawString(1250, 705, "OK", 0x000000);
	}
	else
	{
		DrawBox(308 + 85 * CursorPoint.x, 353 + 85 * CursorPoint.y,
			383 + 85 * CursorPoint.x, 430 + 85 * CursorPoint.y, 0x808080, TRUE);
		//普通の文字色の”確定”を描画する
		DrawString(1250, 705, "OK", 0xffffff);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 14; j++) {
			if (j == CursorPoint.x && i == CursorPoint.y) {
				//I、i、Lの文字の空白を調整する
				if (i == 0 && j == 8 && KeyBoard[0][8] || i == 2 && j == 8 && KeyBoard[2][8] || i == 2 && j == 11 && KeyBoard[2][11]) {
					DrawFormatString(j * 85 + 328, i * 85 + 355, 0x000000,"%c", KeyBoard[i][j]);
				}
				//gの文字高さを調整する
				else if (i == 2 && j == 6 && KeyBoard[0][8]) {
					DrawFormatString(j * 85 + 318, i * 85 + 348, 0x000000, "%c", KeyBoard[i][j]);
				}
				else
				{
					DrawFormatString(j * 85 + 318, i * 85 + 355, 0x000000, "%c", KeyBoard[i][j]);
				}
			}
			else
			{
				//I、i、Lの文字の空白を調整する
				if (i == 0 && j == 8 && KeyBoard[0][8] || i == 2 && j == 8 && KeyBoard[2][8] || i == 2 && j == 11 && KeyBoard[2][11]) {
					DrawFormatString(j * 85 + 328, i * 85 + 355, 0xffffff, "%c", KeyBoard[i][j]);
				}
				//gの文字高さを調整する
				else if (i == 2 && j == 6 && KeyBoard[0][8]) {
					DrawFormatString(j * 85 + 318, i * 85 + 348, 0xffffff,"%c", KeyBoard[i][j]);
				}
				else
				{
					DrawFormatString(j * 85 + 318, i * 85 + 355, 0xffffff, "%c", KeyBoard[i][j]);
				}

			}

		}
	}
	DrawString(100, 840, "STARTボタン or OKで確定", 0xffffff);
}
