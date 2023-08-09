#pragma once
#include"SphereCollider.h"
#include"Define.h"

class Bullet:
	public SphereCollider
{
private:
	int damage;				//与えるダメージ
	float speed;			//速度
	float angle;			//角度
	float acceleration;		//加速度
	float angulVelocity;	//角度の変化量

public:

	//コンストラクタ
	Bullet(float x, float y, float radius);

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
};


