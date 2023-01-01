#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalFields.h"


class Floor : public sf::Drawable
{
public:
	Floor(sf::Color waterColor);
	sf::Texture waterTexture;
	sf::Sprite waterSprite;
	sf::Color waterColor;

	sf::Color WaterLowLOD;

	sf::Vector2f waterSpeed = { 10.f, 0.f };
	sf::Vector2f waterOffSet;

	void Update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Color AverageColor(sf::Texture texture);
};

