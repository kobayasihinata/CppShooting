#include"Dxlib.h"
#include"define.h"
#include"NwaySpawner.h"

void NwaySpawner::Shoot(GameMainScene* gm_scene, float x, float y, float radius, int who, float angle, int b_type)
{
	switch (b_type)
	{
	case SINGLE_SHOT:
		gm_scene->SpawnBullet(x, y, radius, who, angle);
		break;
	case TWIN_SHOT:
		AngleDiff = 0.1f;
		BaseAngle = angle + (AngleDiff / 2);
		for (int i = 0; i < 2; i++)
		{
			gm_scene->SpawnBullet(x, y, radius, who, BaseAngle - (i* AngleDiff));
		}
		break;
	case TRIPLE_SHOT:
		AngleDiff = 0.05f;
		BaseAngle = angle + AngleDiff;
		for (int i = 0; i < 3; i++)
		{
			gm_scene->SpawnBullet(x, y, radius, who, BaseAngle - (i * AngleDiff));
		}
		break;

	}
}
