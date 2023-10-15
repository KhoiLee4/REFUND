#pragma once

class Location
{
private:
	std::vector<sf::Texture> locationTextures;
	std::vector<sf::Sprite> locationSprite;
	std::vector<sf::Texture> itemTextures;
	std::vector<sf::Sprite> itemSprite;
	
	void initItemTextures();
	void initItemSprite();
	void initItemPosition();
	void initItem();

	void initLocationTextures();
	void initLocationSprite();
	void initLocationPosition();
	void initLocation();
public:
	Location();
	virtual ~Location();

	//Fuctions
	void update();
	void render(sf::RenderTarget& target);
	//Fuctions
};

