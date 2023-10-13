#pragma once

#include "Item.h"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	Item* item;
	Player* player;

	void initWindow();
	void initItem();
	void initPlayer();
public:
	//Functions

	Game();
	virtual ~Game();

	//Functions
	void updateItem();
	void updatePlayer();
	void update();
	void renderItem();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

