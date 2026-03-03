#include <SFML/Graphics/CircleShape.hpp>

struct CShape
{
	sf::CircleShape circle;

	CShape(float radius, const sf::Color& fillColor)
	{
		circle.setRadius(radius);
		circle.setFillColor(fillColor);
		circle.setOrigin({ radius, radius });
	}
};