#include"Dxlib.h"
#include"BulletsSpawner.h"

void BulletsSpawner::Shoot(GameMainScene* gm_scene, int x, int y, int type)
{
	gm_scene->SpawnBullet(x, y, 10, type);
}
