#pragma once
#include"SphereCollider.h"
#include"Define.h"

class Bullet:
	public SphereCollider
{
private:
	int frame;				//フレーム計算用
	int who_shot;			//誰が撃った弾か　1 = player  -1 = enemy
	int b_type;				//弾の種類
	int damage;				//与えるダメージ
	float b_speed;			//速度
	float angle;			//角度
	float acceleration;		//加速度
	float angle_velocity;	//角度の変化量
	int bend_time;			//曲がる弾用
	float rad;				//角度計算用
	float base_angle;		//最初のアングル

public:

	//コンストラクタ（スポーンするX座標、Y座標、弾の半径、弾の速度、誰が打ち出したか、弾の移動角度）
	Bullet(float x, float y, float radius, float speed, int who, float b_angle);

	//デストラクタ
	~Bullet();

	//描画以外の更新
	void Update();

	//描画の更新
	void Draw()const;

	//ダメージ量を取得
	int GetDamage() { return damage; }

	//座標を取得
	Location GetLocation() { return location; }

	//誰から出た弾か判断
	int GetBulletType() { return who_shot; }

	//弾の角度を取得
	float GetAngle() { return angle; }
};


