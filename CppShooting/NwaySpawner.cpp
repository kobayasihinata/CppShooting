#include"Dxlib.h"
#include"define.h"
#include"NwaySpawner.h"

void NwaySpawner::Shoot(GameMainScene* gm_scene, float x, float y, float radius, float speed, int who, float angle, int b_type)
{
	numBullets = b_type;
	AngleDiff = 0.05f;
	BaseAngle = angle - ((AngleDiff * numBullets) / 2) + AngleDiff/2;

	for (int i = 0; i < numBullets; i++)
	{
		gm_scene->SpawnBullet(x, y, radius, speed, who, BaseAngle + (i * AngleDiff));
	}
}
void NwaySpawner::Shoot(WeaponPickScene* w_pick, float x, float y, float radius, float speed, int who, float angle, int b_type)
{
	numBullets = b_type;
	AngleDiff = 0.05f;
	BaseAngle = angle - ((AngleDiff * numBullets) / 2) + AngleDiff / 2;

	for (int i = 0; i < numBullets; i++)
	{
		w_pick->SpawnBullet(x, y, radius, speed, who, BaseAngle + (i * AngleDiff));
	}
}
