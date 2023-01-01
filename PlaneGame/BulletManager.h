#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <List>

class Bullet;

class BulletManager : public sf::Drawable
{
public:
	std::list<Bullet*> bullets;

	BulletManager();

	void Update(float dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

