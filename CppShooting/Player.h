#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;
class WeaponPickScene;

class Player :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
	int score;		//点数
	float angle;	//弾の角度
	float power;		//弾の強さ
	int bullet_size;	//弾の大きさ

	int weapon_type;	//武器の種類
	float BaseAngle;	//発射する最初の弾の向きを描画する用
	float AngleDiff;	//弾同士の角度差を描画する用

	int b_speed;		//弾の速度
	int shot_span;		//弾の発射間隔

public:

	Player();
	~Player();
	void Update(GameMainScene* g_main)override;
	void Update(WeaponPickScene* w_pick);
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
	void SetWeaponType(int type) { weapon_type = type; }
};
