#pragma once
#include "SceneBase.h"
#include "Define.h"
#include "PadInput.h"

#include "Player.h"

class Player;
class Bullet;

class WeaponPickScene:
	public SceneBase
{
private:
	Player* player;
	Bullet* bullet[MAX_BULLET];
	int pick_cursor;	//武器選択カーソルの位置
	int now_current;		//選択中の武器
public:
	//コンストラクタ
	WeaponPickScene();

	//デストラクタ
	~WeaponPickScene();

	//描画以外の更新
	SceneBase* Update()override;

	//描画の更新
	void Draw()const override;

	//弾の配列に新しくデータを作成する（スポーンするX座標、Y座標、弾の半径、弾の速度、誰が打ち出したか、弾の移動角度）
	void SpawnBullet(float x, float y, int radius, float speed, int who, float angle);
};