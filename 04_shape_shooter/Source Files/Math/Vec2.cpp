#include "Vec2.h"

Vec2::Vec2()
{
}

Vec2::Vec2(float x, float y)
	:x(x)
	,y(y)
{
}

Vec2::Vec2(sf::Vector2i vec2i)
	:x(vec2i.x)
	,y(vec2i.y)
{
}

Vec2::operator sf::Vector2f() const
{
	return sf::Vector2f(x, y);
}


