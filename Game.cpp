#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	//Create game window
	this->window.create(sf::VideoMode(800, 600), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	this->window.setFramerateLimit(144);
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
	this->initItem();
	this->initPlayer();
}
Game::~Game()
{
	delete this->item;
	delete this->player;
}

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

	this->updateItem();
	this->updatePlayer();
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
	this->renderItem();
	this->renderPlayer();
	this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}

