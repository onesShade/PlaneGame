#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalFields.h"

class Player : public sf::Drawable
{
public:
	Player();

	sf::Texture mainTexture;
	sf::Sprite mainSprite;

	sf::Texture shadowTexture;
	sf::Sprite shadowSprite;

	sf::Vector2f shadowOffset = { -120.f, 120.f };
	float shadowSizeScale = 0.6f;

	float angularVelosity = 12.f;
	float velosity = 200.f;
	//for this unique sprite
	float gunOffSetLength = 25.5f;
	float defaultGunAngle = 0.8f;

	float shootTimerFull = 0.08f;
	float shootTimer = shootTimerFull;

	void Update(float dt, BulletManager &bulletManager);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Vector2f GetViewPosition();
};

