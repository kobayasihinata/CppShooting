#pragma once
#include "SceneBase.h"

class DrawRanking :
	public SceneBase
{
private:

public:
	//コンストラクタ
	DrawRanking();

	//デストラクタ
	~DrawRanking();

	//描画以外の更新を実行
	SceneBase* Update() override;

	//描画に関することを実装
	void Draw() const override;
};



