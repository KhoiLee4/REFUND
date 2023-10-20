#pragma once

#include "Location.h"
#include "ItemPick.h"
#include "Item.h"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;
	bool keyE = true;
	bool keyPressed = false;
	std::vector<sf::Texture> locationTextures;
	std::vector<sf::Texture> itemTextures;
	std::vector<sf::Sprite> locationSprite;
	std::vector<sf::Sprite> itemSprite;

	Location* location;
	ItemPick* itemPick;
	Item* item;
	Player* player;

	void initWindow(); 
	//void initLocationTextures();
	void initLocation();
	void initItemPick();
	void initItem();
	void initPlayer();
public:
	//Functions

	Game();
	virtual ~Game();

	//Functions 
	bool isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition, float thresholdDistance);
	void updateLocation();
	void updatePickSpritePosition();
	//void updateItemPick();
	//void updateItem();
	void updatePlayer();
	void update();
	void renderNearLocation();
	void renderLocation();
	void renderItemPick();
	void renderItem();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

