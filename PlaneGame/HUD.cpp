#include "HUD.h"

HUD::HUD()
{
	HUDView = new sf::View({0,0 , (float)windowWidth, (float)windowHeight});
}


void HUD::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.setView(*HUDView);
	//
	//sf::RectangleShape rec({100,100});
	//rec.setFillColor(sf::Color::Black);
	//target.draw(rec, states);
}

