#pragma once

#include "Done.h"
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
	//std::vector<bool> done;
	//sf::Texture doneTexture;
	//sf::Sprite doneSprite;

	Done* done;
	Location* location;
	ItemPick* itemPick;
	Item* item;
	Player* player;

	void initWindow(); 
	void initDone();
	void initLocation();
	void initItemPick();
	void initItem();
	void initPlayer();
public:
	//Functions

	Game();
	virtual ~Game();

	//Functions 
	void updateDone();
	//void shuffle(std::vector<sf::Texture>& texture);
	void updateLocation(int i);
	bool isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition, float thresholdDistance);
	void updatePickSpritePosition();
	void updatePlayer();
	void update();

	void renderItemLocation(int i);
	void renderNearLocation();
	void renderLocation();
	void renderItemPick();
	void renderItem();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

