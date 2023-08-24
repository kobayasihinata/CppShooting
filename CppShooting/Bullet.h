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
	int hit_count;			//敵を何体貫通するか
	int b_color;			//弾の色
	int delete_time;		//弾を消すまでの時間

public:

	//コンストラクタ（弾情報構造体）
	Bullet(BulletData b_data);

	//デストラクタ
	~Bullet();

	//描画以外の更新
	void Update(float player_x,float player_y);

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

	//敵に当たった時に貫通するか判断
	int GetHitCount() { return --hit_count; }

	//弾の色選択
	int GetBulletColor(int type);

	//弾を消す時間か判断
	int GetDeleteTime() { return delete_time; }
};


