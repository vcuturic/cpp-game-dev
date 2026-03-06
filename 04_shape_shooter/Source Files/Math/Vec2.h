#pragma once
#include <SFML/System/Vector2.hpp>

class Vec2
{
public:
	float x = 0;
	float y = 0;

	Vec2();
	Vec2(float x, float y);

	operator sf::Vector2f() const;
};