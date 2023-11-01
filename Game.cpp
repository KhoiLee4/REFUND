#include "stdafx.h"
#include "Game.h"
#include <random>

void Game::initWindow()
{
	//Create game window
	this->window.create(sf::VideoMode(800, 600), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	this->window.setFramerateLimit(144);
}

void Game::initDone()
{
	this->done = new Done();
}

//void Game::initDone()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		this->done[i] = false;
//	}
//	this->doneTexture.loadFromFile("Data/Textures/Done/done.jpg");
//	this->doneSprite.setTexture(this->doneTexture);
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
	this->initDone();
	this->initLocation();
	this->initItemPick();
	this->initItem();
	this->initPlayer();
}
Game::~Game()
{
	delete this->done;
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

//bool Game::checkDone()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		if (done[i] == false) return false;
//	}
//	return true;
//}

//void Game::shuffle(std::vector<sf::Texture>& texture)
//{
//	std::random_device rd;  // Tạo một thiết bị ngẫu nhiên
//	std::mt19937 g(rd());   // Tạo một generator ngẫu nhiên
//
//	std::shuffle(texture.begin(), texture.end()-1, g);  // Sử dụng std::shuffle để xáo trộn vector
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
	/*this->shuffle(this->item->itemTextures);
	this->shuffle(this->location->itemTextures);*/
	//Polling widow events
	float thresholdDistance = 15.0f; // Khoảng cách tối thiểu để xem là đã đến gần
	int i = 0;
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::E && this->keyPressed == false)
		{
			std::cout << "Phim E duoc nhan" << std::endl;
			if (this->keyE == true && !this->done->check())
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
				
				if(!this->done->check() && i<6)
				{
						/*if (this->itemPick->pickItem == i)
						{*/
							if (isNearObject(this->player->getThiefPosition(), this->location->getLocationPosition(i), thresholdDistance))
							{
								std::cout << "Tra do ne" << std::endl;
								std::cout << "i = " << i << std::endl;
								this->updateLocation(i);
								this->itemPick->updateRestore();
								this->keyE = true;
								this->location->eraseItem[i] = true;
								this->done->updateCheck(i);
								i++;
							}
						/*}*/
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
	float thresholdDistance = 15.0f; // Khoảng cách tối thiểu để xem là đã đến gần
	for (int i = 0; i < 6; i++)
	{
		if (this->done->getDoneCheck(i) == false)
		{
			if (isNearObject(this->player->getThiefPosition(), this->location->getLocationPosition(i), thresholdDistance))
				this->renderItemLocation(i);
		}
		else
		{
			this->done->render(this->window, i);
		}
	}
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

