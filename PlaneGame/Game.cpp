#include "Game.h"

void Game::Start()
{
    enemy = new EnemyPlane(&player);
    bulletManager = new BulletManager();
    mainFpsCounter = new FpsCounter();
    window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Plane Game");
    floor = new Floor(sf::Color(0x3333FFFF));
    MainView = new sf::View(window->getView());
    hud = new HUD();
}
void Game::Run()
{
    

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
    
            if (event.type == sf::Event::KeyReleased)
                switch (event.key.code)
                {
                case sf::Keyboard::F3:
                    mainFpsCounter->active = !mainFpsCounter->active;
                    break;
                case sf::Keyboard::Up:
                    MainView->zoom(0.9);
                    break;
                case sf::Keyboard::Down:
                    MainView->zoom(1.1);
                    break;
                }
        }
    
    
        float delta_time = deltaTimeClock.restart().asSeconds();
    
        MainView->setCenter(player.GetViewPosition());
        

        mainFpsCounter->Update(delta_time);
        player.Update(delta_time,*bulletManager);
        floor->Update(delta_time);
        bulletManager->Update(delta_time);
        enemy->Update(delta_time,*bulletManager);

        Draw();

       
    }
}


void Game::Draw()
{
    window->clear(sf::Color::White);

    window->setView(*MainView);
    window->draw(*floor);
    window->draw(player);
    window->draw(*enemy);
    window->draw(*bulletManager);
    
    window->draw(*hud);
    window->draw(*mainFpsCounter);
    
    window->display();
}