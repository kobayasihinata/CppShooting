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

	int time;	//クリアタイム格納用
	int score;	//スコア格納用
	bool x_once;	//Lスティック入力重複防止用（横）
	bool y_once;	//Lスティック入力重複防止用（縦）

	std::string name;	//名前入力用

	POINT cursor_point;	//カーソルの座標用

	//入力可能文字格納
	const char keyboard[5][14] = { "ABCDEFGHIJKLM" ,"NOPQRSTUVWXYZ" ,"abcdefghijklm" ,"nopqrstuvwxyz" ,"0123456789" };

public:

	//コンストラクタ
	InputRankingScene(int score,int _time);

	//デストラクタ
	~InputRankingScene();

	//描画以外の更新を実行
	SceneBase* Update()override;

	//描画に関することを実装
	void Draw()const override;
};



