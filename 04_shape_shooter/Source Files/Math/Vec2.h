#pragma once
#include <SFML/System/Vector2.hpp>

class Vec2
{
public:
	int x = 0;
	int y = 0;

	Vec2();
	Vec2(float x, float y);
	Vec2(sf::Vector2i vec2i);

	operator sf::Vector2f() const;
};