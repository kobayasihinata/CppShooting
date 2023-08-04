#include"SphereCollider.h"
#include<math.h>

bool SphereCollider::CheckCollision(SphereCollider* s_collider)
{
	bool ret = false;

	float x1 = location.x;
	float y1 = location.y;
	float r1 = location.radius;

	float x2 = s_collider->GetLocation().x;
	float y2 = s_collider->GetLocation().y;
	float r2 = s_collider->GetLocation().radius;

	float a = x1 - x2;
	float b = y1 - y2;
	float c = sqrt(a * a + b * b);

	if (c <= r1 + r2)
	{
		ret = true;
	}
	return ret;
}

Location SphereCollider::GetLocation()
{
	return location;
}