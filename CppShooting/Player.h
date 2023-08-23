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
	int score;		//“_”
	float angle;	//’e‚ÌŠp“x
	float power;		//’e‚Ì‹­‚³
	int bullet_size;	//’e‚Ì‘å‚«‚³

	int weapon_type;	//•Ší‚Ìí—Ş
	float BaseAngle;	//”­Ë‚·‚éÅ‰‚Ì’e‚ÌŒü‚«‚ğ•`‰æ‚·‚é—p
	float AngleDiff;	//’e“¯m‚ÌŠp“x·‚ğ•`‰æ‚·‚é—p

	int b_speed;		//’e‚Ì‘¬“x
	int shot_span;		//’e‚Ì”­ËŠÔŠu

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
