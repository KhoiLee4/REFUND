#pragma once

class Location
{
private:
	std::vector<sf::Texture> locationTextures;
	std::vector<sf::Texture> itemTextures;
	

	/*sf::Texture itemTextures;
	sf::Texture locationTextures;
	sf::Sprite itemSprite;
	sf::Sprite locationSprite;*/

	bool keyPressed = false;
	
	//bool keyE = true;

	void initItemTextures();
	void initItemSprite();
	void initItemPosition();
	void initItem();

	void initLocationTextures();
	void initLocationSprite();
	void initLocationPosition();
	void initEraseItem();
	void initLocation();
public:
	Location();
	virtual ~Location();

	std::vector<sf::Sprite> locationSprite;
	std::vector<sf::Sprite> itemSprite;
	std::vector<bool> eraseItem;

	//Fuctions
	sf::Vector2f getLocationPosition(int i);
	void updateItem(int i);
	void update();
	void renderItem(sf::RenderTarget& target, int i);
	//void renderLocation(sf::RenderTarget& target);
	void render(sf::RenderTarget& target, int i);
	//Fuctions
};

