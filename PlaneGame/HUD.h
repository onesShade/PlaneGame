#pragma once
#include <SFML/Graphics.hpp>
#include "GlobalFields.h"




class HUD : public sf::Drawable
{
public:
	HUD();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::View* HUDView;
};

