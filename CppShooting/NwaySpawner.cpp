#include"Dxlib.h"
#include"NwaySpawner.h"

void NwaySpawner::Shoot(GameMainScene* gm_scene)
{
	gm_scene->SpawnBullet(100, 100, 10, 0);
}
