#include "Host.h"

void Host::initVariables()
{
	this->animState = HOST_ANIMATION_STATES::SLEEP;
}

void Host::initTexture()
{
	// lay hinh tu data vao
	if (!this->textureSheet.loadFromFile("Data/Textures/Host/host-sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the host sheet!" << '\n';
	}
}

void Host::initSprite()
{
	this->hostSprite.setTexture(this->textureSheet); // gan hinh anh
	this->currentFrame = sf::IntRect(0, 0, 84.8, 87); // cai dat kich thuoc hinh cat
	this->hostSprite.setTextureRect(this->currentFrame); // cat hinh
	this->hostSprite.setScale(1.5f, 1.5f); //Increase sprite size
	this->hostSprite.setPosition(hostX, hostY); // cai dat vi tri cho chu nha
}	

void Host::initAnimations()
{
	this->animationTimer.restart(); // bat dau tinh thoi gian chay
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

void Host::moveHost(float x, float y)
{
	hostSprite.move(x, y);
}

void Host::updateVariables()
{
	this->animState = HOST_ANIMATION_STATES::WAKEUP;
}

void Host::updateAnimation()
{
	// truong hop chu nha ngu
	if (this->animState == HOST_ANIMATION_STATES::SLEEP)
	{
		// thuc hien thay doi hinh anh chu nha qua moi 0.3 giay (tao chuyen dong)
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			// di chuyen sang khung hinh ke tiep de tao chuyen dong
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 84.8f;
			if (this->currentFrame.left >= 424.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart(); // dat lai thoi gian
			this->hostSprite.setTextureRect(this->currentFrame); // cap nhat hinh cat
		}
	}
	// truong hop chu nha thuc
	else if (this->animState == HOST_ANIMATION_STATES::WAKEUP)
	{
		// thuc hien thay doi hinh anh chu nha qua moi 0.3 giay (tao chuyen dong)
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			// di chuyen sang khung hinh ke tiep de tao chuyen dong
			this->currentFrame.top = 87.f;
			this->currentFrame.left += 84.8f;
			if (this->currentFrame.left >= 424.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart(); // dat lai thoi gian
			this->hostSprite.setTextureRect(this->currentFrame); // cap nhat hinh cat
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

