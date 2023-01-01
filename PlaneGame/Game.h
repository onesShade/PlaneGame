#pragma once
#include <SFML/Graphics.hpp>
#include "HUD.h" 
#include "Player.h" 
#include "Floor.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "GlobalFields.h" 
#include "EnemyPlane.h" 

class Player;
class Game
{
public:
	Player player;
	EnemyPlane *enemy;
	HUD *hud;
	BulletManager *bulletManager;
	Floor* floor;
	sf::Clock deltaTimeClock;
	sf::View *MainView;
	sf::RenderWindow *window;


	void Start();
	void Run();
	void Draw();
};

