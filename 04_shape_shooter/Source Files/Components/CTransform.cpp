#include "../Math/Vec2.h"

struct CTransform
{
public:
	Vec2 position = { 0.0, 0.0 };
	Vec2 velocity = { 0.0, 0.0 };
	float angle = 0.0f;

	CTransform() {}

	CTransform(const Vec2 &pos, const Vec2 &vel, float a)
		:position(pos)
		,velocity(vel)
		,angle(a)
	{
	}
};