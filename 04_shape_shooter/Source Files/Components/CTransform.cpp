#include <SFML/System/Vector2.hpp>

struct CTransform
{
	sf::Vector2f position;
	sf::Vector2f velocity;
	float angle = 0.0f;
};