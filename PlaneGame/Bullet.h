#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalFields.h"

class Bullet : public sf::Drawable
{
public:
	Bullet(sf::Vector2f pos, sf::Vector2f movement_vector, float parent_velosity);
	sf::RectangleShape bullet;
	sf::Vector2f movementVector;
	float velosity = 500.f;
	float timeInAir;
	const float maxTimeInAir = 8.f;
	bool dead;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void Update(float dt);

};

