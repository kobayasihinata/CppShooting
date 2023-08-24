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

	int interbal;	//’e”­ËŠÔŠu
	float b_angle;	//’eŠp“x
	int delete_time;//’e‚ğÁ‚·‚Ü‚Å‚ÌŠÔ
	int b_type;		//’e‚Ìí—Ş
public:
	Enemy(int x,int y);
	~Enemy();
	void Update(GameMainScene* g_main)override;
	void Draw()const override;
	void Hit()override;
	Location GetLocation() { return location; }
	NwaySpawner* weapon() { return n_spawner; }
	//’e”­Ë—pƒf[ƒ^‚ğ‚Ü‚Æ‚ß‚Ä\‘¢‘Ì‚ğ•Ô‚·
	BulletData UpdateBulletData();
};

