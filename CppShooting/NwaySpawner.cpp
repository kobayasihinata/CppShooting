#include"Dxlib.h"
#include"define.h"
#include"NwaySpawner.h"

void NwaySpawner::Shoot(GameMainScene* gm_scene, int x, int y, int who, float angle, int b_type)
{
	switch (b_type)
	{
	case SINGLE_SHOT:
		gm_scene->SpawnBullet(x, y, 10, who, angle);
		break;
	case TWIN_SHOT:
		AngleDiff = 0.1f;
		BaseAngle = angle + (AngleDiff / 2);
		for (int i = 0; i < 2; i++)
		{
			gm_scene->SpawnBullet(x, y, 10, who, BaseAngle - (i* AngleDiff));
		}
		break;

	}
}
