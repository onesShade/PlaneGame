#include "Player.h"
#include <iostream>

Player::Player()
{
	if (!mainTexture.loadFromFile(texturesSheetPath, { 0,0,64,64 }))
		throw("texture not loaded");
	if (!shadowTexture.loadFromFile(texturesSheetPath, { 0,128,64,64 }))
		throw("texture not loaded");

	mainSprite.setTexture(mainTexture);
	shadowSprite.setTexture(shadowTexture);

	mainSprite.setOrigin(mainTexture.getSize().x / 2, mainTexture.getSize().y / 2);
	shadowSprite.setOrigin(mainSprite.getOrigin());

	mainSprite.scale({ texturesScale, texturesScale });
	shadowSprite.scale(mainSprite.getScale() * shadowSizeScale);
	gunOffSetLength *= texturesScale;
	mainSprite.setPosition({windowWidth * 0.5f ,windowHeight * planeOffSet});
	shadowSprite.setPosition(mainSprite.getPosition() + shadowOffset);

}

void Player::Update(float dt, BulletManager& bulletManager)
{
	short rot = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		rot--;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		rot++;
	if(rot != 0)
		mainSprite.rotate(dt * angularVelosity * rot);

	float angle = mainSprite.getRotation() * 3.14f / 180.f;
	mainSprite.move(sf::Vector2f(std::sinf(angle),-std::cosf(angle))  * velosity * dt);

	shadowSprite.setPosition(mainSprite.getPosition() + shadowOffset);
	shadowSprite.setRotation(mainSprite.getRotation());

	if (shootTimer < 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			float angle2 = mainSprite.getRotation() * 3.14f / 180.f + defaultGunAngle;
			sf::Vector2f rotational_gun_offset = sf::Vector2f(-std::cosf(angle2), -std::sinf(angle2)) * gunOffSetLength;

			bulletManager.bullets.push_back(new Bullet(mainSprite.getPosition() + rotational_gun_offset,
				{ std::sinf(angle), -std::cosf(angle) }, velosity));


			angle2 = mainSprite.getRotation() * 3.14f / 180.f - defaultGunAngle;
			rotational_gun_offset = sf::Vector2f(std::cosf(angle2), std::sinf(angle2)) * gunOffSetLength;

			bulletManager.bullets.push_back(new Bullet(mainSprite.getPosition() + rotational_gun_offset,
				{ std::sinf(angle), -std::cosf(angle) }, velosity));

		shootTimer = shootTimerFull;
		}
	}
	else
		shootTimer -= dt;
	std::cout << bulletManager.bullets.size() << "\n";
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape look({ 2, 300 });

	if (mainFpsCounter != NULL && mainFpsCounter->active)
	{
	look.setFillColor(sf::Color::Green);
	look.setOrigin(1, 300);
	look.setPosition(mainSprite.getPosition());
	look.setRotation(mainSprite.getRotation());
	target.draw(look, states);
	}
	target.draw(mainSprite, states);
	target.draw(shadowSprite, states);
}

sf::Vector2f Player::GetViewPosition()
{
	float path = windowHeight * (planeOffSet - 0.5f);
	float angle = mainSprite.getRotation() * 3.14f / 180.f;
	return sf::Vector2f(sf::Vector2f(std::sinf(angle), -std::cosf(angle))) * path + mainSprite.getPosition();
}
