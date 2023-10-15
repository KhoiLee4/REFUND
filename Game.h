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

	Location* location;
	ItemPick* itemPick;
	Item* item;
	Player* player;

	void initWindow();
	void initLocation();
	void initItemPick();
	void initItem();
	void initPlayer();
public:
	//Functions

	Game();
	virtual ~Game();

	//Functions
	//bool isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition, float thresholdDistance);
	void updateLocation();
	void updatePickSpritePosition();
	void updateItemPick();
	void updateItem();
	void updatePlayer();
	void update();
	void renderLocation();
	void renderItemPick();
	void renderItem();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

