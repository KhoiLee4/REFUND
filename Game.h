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
	/*std::vector<sf::Texture> locationTextures;
	std::vector<sf::Texture> itemTextures;
	std::vector<sf::Sprite> locationSprite;
	std::vector<sf::Sprite> itemSprite;*/

	/*std::vector<bool> eraseItem;*/

	Location* location;
	ItemPick* itemPick;
	Item* item;
	Player* player;

	void initWindow(); 
	//void initEraseItem();
	//void initItemTextures();
	//void initItemSprite();
	//void initItemPosition();
	//void initItemLocation();
	//void initLocationTextures();
	//void initLocationSprite();
	//oid initLocationPosition();
	//void initLocations();
	void initLocation();
	void initItemPick();
	void initItem();
	void initPlayer();
public:
	//Functions

	Game();
	virtual ~Game();

	//Functions 
	//sf::Vector2f getLocationPosition(int i);
	void updateLocation(int i);
	bool isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition, float thresholdDistance);
	//void updateLocation();
	void updatePickSpritePosition();
	//void updateItemPick();
	//void updateItem();
	void updatePlayer();
	void update();

	void renderItemLocation(int i);
	//void renderLocations();
	void renderNearLocation();
	void renderLocation();
	void renderItemPick();
	void renderItem();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};

