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
	int power;		//弾の強さ
	int bullet_size;	//弾の大きさ

	int weapon_type;	//武器の種類
	float BaseAngle;	//発射する最初の弾の向きを描画する用
	float AngleDiff;	//弾同士の角度差を描画する用

	int b_speed;		//弾の速度
	int shot_span;		//弾の発射間隔
	int player_color;	//プレイヤーの色
	int h_count;		//弾が貫通出来る敵の数
	int delete_time;	//弾を消すまでの時間

public:
	//コンストラクタ
	Player(int w_type);
	//デストラクタ
	~Player();
	//描画以外の更新(ゲームメイン用)
	void Update(GameMainScene* g_main)override;
	//描画以外の更新(武器選択画面用)
	void Update(WeaponPickScene* w_pick);
	//描画の更新
	void Draw()const override;
	//弾が当たった瞬間の処理
	void Hit()override;
	//プレイヤーの座標の取得
	Location GetLocation() { return location; }
	//NwaySpawner呼び出し用
	NwaySpawner* weapon() { return n_spawner; }
	//武器の種類設定
	void SetWeaponType(int type);
	//プレイヤーの色選択
	int GetPlayerColor(int type);
	//弾発射用データをまとめて構造体を返す
	BulletData UpdateBulletData();
};
