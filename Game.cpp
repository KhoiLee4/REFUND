#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	//Create game window
	this->window.create(sf::VideoMode(800, 600), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	this->window.setFramerateLimit(144);
}

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
void Game::updateLocation()
{
	this->location->update();
}
void Game::updatePickSpritePosition()
{
	float pickX, pickY;
	pickX = this->player->getThiefPosition().x;
	pickY = this->player->getThiefPosition().y;
	this->itemPick->pickSprite.setPosition(pickX, pickY - 1.0f);
}
void Game::updateItemPick()
{
	this->itemPick->update();
}
//bool Game::isNearObject(const sf::Vector2f& objectPosition, const sf::Vector2f& targetPosition, float thresholdDistance)
//{
//	float distance = std::sqrt((objectPosition.x - targetPosition.x) * (objectPosition.x - targetPosition.x) +
//		(objectPosition.y - targetPosition.y) * (objectPosition.y - targetPosition.y));
//
//	return distance <= thresholdDistance;
//}
void Game::updateItem()
{
	this->item->update();
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::update()
{
	//Polling widow events
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();
	}
	this->updateLocation();
	this->updatePickSpritePosition();
	this->updateItemPick();
	this->updateItem();
	this->updatePlayer();
}

void Game::renderLocation()
{
	this->location->render(this->window);
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

