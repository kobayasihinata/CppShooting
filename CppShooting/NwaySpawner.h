#pragma once
#include"BulletsSpawner.h"
#include"WeaponPickScene.h"

class WeaponPickScene;

class NwaySpawner:
	public BulletsSpawner
{
private:
	int numBullets;		//発射する弾の数
	float BaseAngle;	//発射する最初の弾の向き
	float AngleDiff;	//弾同士の角度差
public:
	//弾を生成する（ゲームメインのポインタ、X座標、Y座標、半径、速度、誰が打ち出したのか、動く角度、武器の種類、貫通する敵の数）
	void Shoot(GameMainScene* gm_scene, BulletData b_data)override;
	//弾を生成する（武器選択画面のポインタ、X座標、Y座標、半径、速度、誰が打ち出したのか、動く角度、武器の種類、貫通する敵の数）
	void Shoot(WeaponPickScene* w_pick, BulletData b_data);
	//弾発射用データをまとめて構造体を返す
	BulletData UpdateBulletData(BulletData b_data, int i);
};
