#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("Data/Textures/Character/Thief_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << '\n';
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0,0,32,48);
	this->sprite.setTextureRect(this->currentFrame); //Cutting sprite
	this->sprite.setScale(1.5f, 1.5f); //Increase sprite size
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{
}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		this->sprite.move(0.f, -1.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
	}
	else this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::updateAnimation()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE) 
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left = 0.f;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_DOWN)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 48.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 128.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 96.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 128.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 144.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 128.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_UP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 192.f;
			this->currentFrame.left += 32.f;
			if (this->currentFrame.left >= 128.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}

}

void Player::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
