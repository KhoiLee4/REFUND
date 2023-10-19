#pragma once

class Location
{
private:
	//std::vector<sf::Texture> locationTextures;
	//std::vector<sf::Texture> itemTextures;
	//std::vector<sf::Sprite> locationSprite;
	//std::vector<sf::Sprite> itemSprite;

	sf::Texture itemTextures;
	sf::Texture locationTextures;
	sf::Sprite itemSprite;
	sf::Sprite locationSprite;
	bool keyPressed = false;
	bool eraseItem = false;

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
	sf::Vector2f getLocationPosition();
	void updateItem();
	void update();
	void renderItem(sf::RenderTarget& target);
	//void renderLocation(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
	//Fuctions
};

