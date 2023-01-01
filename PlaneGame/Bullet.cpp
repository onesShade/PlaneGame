#include "Bullet.h"

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(bullet, states);
}

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f movement_vector, float parent_velosity)
{
	velosity += parent_velosity;
	dead = false;
	timeInAir = 0.f;
	movementVector = movement_vector;
	bullet.setSize({2.f, 6.f});
	bullet.setPosition(pos);
	bullet.setOrigin(1.f,0.5f);
	bullet.scale(texturesScale, texturesScale);
	bullet.setRotation(std::atan2f(movement_vector.y, movement_vector.x) * 180.f / 3.14f + 90);
	bullet.setFillColor(sf::Color(0xFAFD0FFF));

}
void Bullet::Update(float dt)
{
	timeInAir += dt;
	if (timeInAir >= maxTimeInAir)
		dead = true;
	else
		bullet.move(movementVector * velosity * dt);
}