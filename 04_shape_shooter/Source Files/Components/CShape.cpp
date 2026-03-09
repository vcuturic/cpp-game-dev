#include <SFML/Graphics/CircleShape.hpp>

struct CShape
{
	sf::CircleShape circle;

	CShape() { }

	CShape(float radius,
			int fillR, 
			int fillG, 
			int fillB,
			int outlineThickness,
			int outlineR,
			int outlineG,
			int outlineB,
			int vertices) 
	{
		circle.setRadius(radius);
		circle.setOrigin({ radius, radius });
		circle.setFillColor(sf::Color(fillR, fillG, fillB));
		circle.setOutlineColor(sf::Color(outlineR, outlineG, outlineB));
		circle.setOutlineThickness(outlineThickness);
		circle.setPointCount(vertices);
	}

	CShape(float radius, const sf::Color& fillColor)
	{
		circle.setRadius(radius);
		circle.setFillColor(fillColor);
		circle.setOrigin({ radius, radius });
	}
};