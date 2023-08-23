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
	//弾を生成する（ゲームメインのポインタ、X座標、Y座標、半径、速度、誰が打ち出したのか、動く角度、武器の種類）
	void Shoot(GameMainScene* gm_scene, float x, float y, float radius, float speed, int who, float angle,int b_type)override;
	//弾を生成する（武器選択画面のポインタ、X座標、Y座標、半径、速度、誰が打ち出したのか、動く角度、武器の種類）
	void Shoot(WeaponPickScene* w_pick, float x, float y, float radius, float speed, int who, float angle, int b_type);
};
