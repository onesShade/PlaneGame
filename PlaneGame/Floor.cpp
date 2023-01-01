#include "Floor.h"
#include <iostream>

sf::Color Floor::AverageColor(sf::Texture texture)
{
	sf::Color result(0x00000000);
	
	sf::Image temp;
	temp = texture.copyToImage();

	int i = 0;

	int d_r = 0;
	int d_g = 0;
	int d_b = 0;
	for(int x = 0; x < texture.getSize().x; x++)
		for (int y = 0; y < texture.getSize().y; y++)
		{
			result = temp.getPixel(x, y);
			d_r += result.r;
			d_g += result.g;
			d_b += result.b;
			i++;
		}
	result = sf::Color(d_r / i, d_g / i, d_b / i, 255);

	result = sf::Color(
		(result.r + waterColor.r - 255) < 0 ? 0 : (result.r + waterColor.r - 255),
		(result.g + waterColor.g - 255) < 0 ? 0 : (result.r + waterColor.r - 255),
		(result.b + waterColor.b - 255) < 0 ? 0 : (result.r + waterColor.r - 255),
		255);
	return result;

}



Floor::Floor(sf::Color water_color)
{
	if(!waterTexture.loadFromFile(texturesSheetPath, {64, 0 , 16, 16}))
		throw("texture not loaded");
	waterColor = water_color;
	WaterLowLOD = water_color;
	waterSprite.setTexture(waterTexture);
	waterSprite.setOrigin(waterTexture.getSize().x / 2, waterTexture.getSize().y / 2);
	waterSprite.setScale(texturesScale, texturesScale);
	waterSprite.setColor(waterColor);
}

void Floor::Update(float dt)
{
	waterOffSet += (waterSpeed * dt);
	if (waterOffSet.x >= TileSize)
		waterOffSet.x -= TileSize;
	if (waterOffSet.y >= TileSize)
		waterOffSet.y -= TileSize;
}

void Floor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::View temp_view(target.getView());
	sf::Vector2f left_corner_position = temp_view.getCenter() - temp_view.getSize() * 0.5f;

	sf::Vector2f start_pos = 
		left_corner_position - sf::Vector2f(std::remainderf(left_corner_position.x, TileSize),
	std::remainderf(left_corner_position.y, TileSize));
	
	int horisontal_count = temp_view.getSize().x / TileSize;
	int vertical_count = temp_view.getSize().y / TileSize;

	if (horisontal_count < windowWidth / TileSize * 2)
	{
	sf::Sprite temp(waterSprite);
	for(int x = -1; x < horisontal_count + 2; x++)
		for (int y = -1; y < vertical_count + 2; y++)
		{
			temp.setPosition(start_pos + waterOffSet + sf::Vector2f(x * TileSize, y * TileSize));
			target.draw(temp, states);
		}
	}
	else
	{
		sf::RectangleShape water_rect(sf::Vector2f(TileSize * (horisontal_count + 3), TileSize * (vertical_count + 3)));
		water_rect.setFillColor(WaterLowLOD);

		water_rect.setPosition(start_pos - sf::Vector2f(TileSize, TileSize));
		target.draw(water_rect, states);
			
	}
}