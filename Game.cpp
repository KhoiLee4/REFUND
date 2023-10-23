#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	//Create game window
	this->window.create(sf::VideoMode(800, 600), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	this->window.setFramerateLimit(144);
}

//void Game::initEraseItem()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		this->eraseItem.push_back(true);
//	}
//}
//
//void Game::initItemTextures()
//{
//	for (int i = 1; i <= 6; i++)
//	{
//		sf::Texture texture;
//
//		if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png")) 
//			this->itemTextures.push_back(texture);
//		else {
//			std::cerr << "Failed to load item-2" << i << ".png" << std::endl;
//		}
//	}
//	/*std::cout << "item co " << itemTextures.size();
//	std::cout << '\n';*/
//}
//
//void Game::initItemSprite()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		sf::Sprite sprite;
//		if (i < this->itemTextures.size())
//		{
//			sprite.setTexture(this->itemTextures[i]);
//			this->itemSprite.push_back(sprite);
//		}
//		else
//		{
//			std::cout << "Khong the set Sprite cho location item thu " << i;
//			std::cout << '\n';
//		}
//	}
//}
//
//void Game::initItemPosition()
//{
//	if (this->itemSprite.size() == 6)
//	{
//		this->itemSprite[0].setPosition(250, 350 - 20);
//		this->itemSprite[1].setPosition(300, 400 - 20);
//		this->itemSprite[2].setPosition(350, 450 - 20);
//		this->itemSprite[3].setPosition(400, 500 - 20);
//		this->itemSprite[4].setPosition(450, 500 - 20);
//		this->itemSprite[5].setPosition(500, 550 - 20);
//	}
//}
//
//void Game::initItemLocation()
//{
//	this->initItemTextures();
//	this->initItemSprite();
//	this->initItemPosition();
//}
//
//void Game::initLocationTextures()
//{
//	for (int i = 1; i <= 6; i++)
//	{
//		sf::Texture texture;
//
//		if (texture.loadFromFile("Data/Textures/Locations/location" + std::to_string(i) + ".png")) {
//			this->locationTextures.push_back(texture);
//		}
//		else {
//			std::cerr << "Failed to load location" << i << ".png" << std::endl;
//		}
//	}
//}
//
//void Game::initLocationSprite()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		sf::Sprite sprite;
//		if (i < this->locationTextures.size())
//		{
//			sprite.setTexture(this->locationTextures[i]);
//			this->locationSprite.push_back(sprite);
//		}
//			
//		else std::cout << "Khong the set Sprite cho location thu " << i << '\n';
//	}
//}
//
//void Game::initLocationPosition()
//{
//	if (this->locationSprite.size() == 6)
//	{
//		this->locationSprite[0].setPosition(250, 350);
//		this->locationSprite[1].setPosition(300, 400);
//		this->locationSprite[2].setPosition(350, 450);
//		this->locationSprite[3].setPosition(400, 500);
//		this->locationSprite[4].setPosition(450, 500);
//		this->locationSprite[5].setPosition(500, 550);
//	}
//}
//
//void Game::initLocations()
//{
//	this->initLocationTextures();
//	this->initLocationSprite();
//	this->initLocationPosition();
//}

void Game::initLocation()
{
	this->location = new Location();
}

void Game::initItemPick()
{
	this->itemPick = new ItemPick();
}

void Game::initItem()
{
	this->item = new Item();
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	//this->initEraseItem();
	//this->initItemLocation();
	this->initLocation();
	this->initItemPick();
	this->initItem();
	this->initPlayer();
}
Game::~Game()
{
	delete this->location;
	delete this->itemPick;
	delete this->item;
	delete this->player;
}

void Game::updatePickSpritePosition()
{
	float pickX, pickY;
	pickX = this->player->getThiefPosition().x;
	pickY = this->player->getThiefPosition().y;
	this->itemPick->pickSprite.setPosition(pickX, pickY - 1.0f);
}

//sf::Vector2f Game::getLocationPosition(int i)
//{
//	if (i < this->location->locationSprite.size()) return this->location->locationSprite[i].getPosition();
//	else
//	{
//		std::cout << "Khong lay duoc vi tri cua location";
//	}
//}

void Game::updateLocation(int i)
{
	this->location->updateItem(i);
}

bool Game::isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition, float thresholdDistance)
{
	float distance = std::sqrt((objectPosition.x - targetPosition.x) * (objectPosition.x - targetPosition.x) +
		(objectPosition.y - targetPosition.y) * (objectPosition.y - targetPosition.y));

	return distance <= thresholdDistance;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::update()
{
	//Polling widow events
	float thresholdDistance = 30.0f; // Khoảng cách tối thiểu để xem là đã đến gần
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::E && this->keyPressed == false)
		{
			std::cout << "Phim E duoc nhan" << std::endl;
			if (this->keyE == true)
			{
				std::cout << "Phim E1 duoc nhan" << std::endl;
				if (isNearObject(this->player->getThiefPosition(), this->item->getItemPosition(), thresholdDistance))
				{
					this->item->updateItem();
					this->itemPick->updatePick();
					this->keyE = false;
				}
			}
			else if (this->keyE == false)
			{
				std::cout << "Phim E2 duoc nhan" << std::endl;
				for (int i = 0; i < 6; i++)
				{
					if (isNearObject(this->player->getThiefPosition(), this->location->getLocationPosition(i), thresholdDistance))
					{
							this->updateLocation(i);
							this->itemPick->updateRestore();
							this->keyE = true;
							this->location->eraseItem[i] = true;
					}
					break;
				}
			}
			this->keyPressed = true;
		}
		else if (this->ev.type == sf::Event::KeyReleased && this->ev.key.code == sf::Keyboard::E) 
		{
			std::cout << "Phim E duoc tha ra" << std::endl;
			this->keyPressed = false;
		}
	}

	this->updatePickSpritePosition();
	this->updatePlayer();
}

void Game::renderItemLocation(int i)
{
	if (i >= 6) std::cout << "Loi khong render ra item location thu" << i;
	else
		if (this->location->eraseItem[i] == true) 
			this->location->renderItem(this->window, i);
}

void Game::renderLocation()
{
	for (int i = 0; i < 6; i++)
	{
		if (i < this->location->locationSprite.size())
			this->location->render(this->window, i);
		else std::cout << "Khong the render duoc location thu " << i;
	}
}

void Game::renderNearLocation()
{
	float thresholdDistance = 30.0f; // Khoảng cách tối thiểu để xem là đã đến gần
	for (int i = 0; i < 6; i++)
	{
		if (isNearObject(this->player->getThiefPosition(), this->location->getLocationPosition(i), thresholdDistance))
		{
			this->renderItemLocation(i);
		}
	}
}

void Game::renderLocation()
{
}

void Game::renderItemPick()
{
	this->itemPick->render(this->window);
}

void Game::renderItem()
{
	this->item->render(this->window);
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//Render game
	//this->renderItemLocation();
	this->renderNearLocation();
	this->renderLocation();
	this->renderItemPick();
	this->renderItem();
	this->renderPlayer();
	this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}

