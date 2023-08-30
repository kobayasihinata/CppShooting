#pragma once
#include"CharaBase.h"
#include"SphereCollider.h"
#include"NwaySpawner.h"

class NwaySpawner;

class Enemy :
	public CharaBase
{
private:
	NwaySpawner* n_spawner;
	int hp;
	int point;

	int interbal;		//弾発射間隔
	int boss_interbal;	//弾連続発射間
	int shot_num;		//一回の発射で何回弾が出るか
	float b_angle;		//弾角度
	int delete_time;	//弾を消すまでの時間
	int b_type;			//弾の種類
	int b_num;			//弾の種類
	bool boss_flg;		//ボスかどうか
	int boss_move;		//ボスの上下移動

	int target_x;		//向かう位置
	int target_y;		//向かう位置
	float angle;		//敵の移動方向
	float rad;			//角度計算用
	float w;			//角度計算用
	float h;			//角度計算用
	int stop_time;		//停止時間
	float spawn_y;		//スポーンした位置（Y座標）

public:
	Enemy(int x, int y, bool bossflg, bool f_flg);
	~Enemy();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	int Hit(int damage)override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
	//弾発射用データをまとめて構造体を返す
	BulletData UpdateBulletData();
	//弾発射用データをまとめて構造体を返す（ボス用弾）
	BulletData UpdateBossBulletData();
};

