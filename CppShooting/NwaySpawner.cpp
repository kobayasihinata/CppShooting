#include"Dxlib.h"
#include"define.h"
#include"NwaySpawner.h"

void NwaySpawner::Shoot(GameMainScene* gm_scene, BulletData b_data)
{
	numBullets = b_data.b_type;
	AngleDiff = 0.05f;
	BaseAngle = b_data.b_angle - ((AngleDiff * numBullets) / 2) + AngleDiff/2;
	for (int i = 0; i < numBullets; i++)
	{
		gm_scene->SpawnBullet(UpdateBulletData(b_data,i));
	}
}
void NwaySpawner::Shoot(WeaponPickScene* w_pick, BulletData b_data)
{
	numBullets = b_data.b_type;
	AngleDiff = 0.05f;
	BaseAngle = b_data.b_angle - ((AngleDiff * numBullets) / 2) + AngleDiff / 2;

	for (int i = 0; i < numBullets; i++)
	{
		w_pick->SpawnBullet(UpdateBulletData(b_data, i));
	}
}
BulletData NwaySpawner::UpdateBulletData(BulletData b_data ,int i)
{
	BulletData bullet_data;
	bullet_data.x = b_data.x;
	bullet_data.y = b_data.y;
	bullet_data.radius = b_data.radius;
	bullet_data.speed = b_data.speed;
	bullet_data.who = b_data.who;
	bullet_data.b_angle = BaseAngle + (i * AngleDiff);
	bullet_data.b_type = b_data.b_type;
	bullet_data.h_count = b_data.h_count;
	return bullet_data;
}
