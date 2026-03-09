#pragma once

struct WindowConfig
{
	unsigned int	width,
					height,
					fps,
					fullscreen;
};

struct FontConfig
{
	int			fontRed,
				fontGreen,
				fontBlue;
	std::string fontName;
};

struct PlayerConfig
{
	int		circleRadius,
			collisionRadius,
			fillRed,
			fillGreen,
			fillBlue,
			outlineThickness,
			outlineRed,
			outlineGreen,
			outlineBlue,
			vertices;
	float	speed;
};

struct EnemyConfig
{
	int		circleRadius,
			collisionRadius,
			outlineThickness,
			outlineRed,
			outlineGreen,
			outlineBlue,
			verticesMin,
			verticesMax,
			L,
			SI;
	float	speedMin,
			speedMax;
};

struct BulletConfig
{
	int		circleRadius,
			collisionRadius,
			fillRed,
			fillGreen,
			fillBlue,
			outlineThickness,
			outlineRed,
			outlineGreen,
			outlineBlue,
			vertices,
			L;
	float	speed;
};
