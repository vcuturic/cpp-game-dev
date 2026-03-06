#include "Vec2.h"

Vec2::Vec2()
{
}

Vec2::Vec2(float x, float y)
	:x(x)
	,y(y)
{
}

Vec2::operator sf::Vector2f() const
{
	return sf::Vector2f(x, y);
}
