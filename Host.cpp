#include "stdafx.h"
#include "Host.h"

void Host::initVariables()
{
	this->animState = HOST_ANIMATION_STATES::SLEEP;
}

void Host::initTexture()
{
	if (!this->textureSheet.loadFromFile("Data/Textures/Host/host-sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the host sheet!" << '\n';
	}
}

void Host::initSprite()
{
	this->hostSprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 84.8, 87);
	this->hostSprite.setTextureRect(this->currentFrame); //Cutting sprite
	//this->hostSprite.setScale(1.5f, 1.5f); //Increase sprite size
	this->hostSprite.setPosition(150, 75);
}

void Host::initAnimations()
{
	this->animationTimer.restart();
}

Host::Host()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Host::~Host()
{
}

sf::Vector2f Host::getHostPosition()
{
	return hostSprite.getPosition();
}

void Host::updateVariables()
{
	this->animState = HOST_ANIMATION_STATES::WAKEUP;
}

void Host::updateAnimation()
{
	if (this->animState == HOST_ANIMATION_STATES::SLEEP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 84.8f;
			if (this->currentFrame.left >= 424.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->hostSprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == HOST_ANIMATION_STATES::WAKEUP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 87.f;
			this->currentFrame.left += 84.8f;
			if (this->currentFrame.left >= 424.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->hostSprite.setTextureRect(this->currentFrame);
		}
	}
}

void Host::update()
{
	this->updateAnimation();
}

void Host::render(sf::RenderTarget& target)
{
	target.draw(this->hostSprite);
}

