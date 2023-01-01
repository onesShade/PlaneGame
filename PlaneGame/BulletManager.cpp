#include "BulletManager.h"



BulletManager::BulletManager()
{

}


void BulletManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (Bullet *bullet : bullets)
	{
		target.draw(*bullet, states);
	}
}

void BulletManager::Update(float dt)
{
	std::list<Bullet*>::iterator iter = bullets.begin();

	while (iter != bullets.end())
	{
		(*iter)->Update(dt);
		if ((*iter)->dead)
		{
			delete(*iter);
			iter = bullets.erase(iter);
		}
		else
			iter++;
	}
}