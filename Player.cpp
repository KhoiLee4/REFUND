#include "Player.h"

void Player::initVariables()
{
	// cai dat ban dau nhan vat dung im
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
}

void Player::initTexture()
{
	// lay hinh tu data vao
	if (!this->textureSheet.loadFromFile("Data/Textures/Character/Thief_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << '\n';
	}
}

void Player::initSprite()
{
	// tao doi tuong trom (nhan vat)
	this->thiefSprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0,0,100,150);
	this->thiefSprite.setTextureRect(this->currentFrame); //Cutting sprite
	this->thiefSprite.setScale(0.8f, 0.8f); //Increase sprite size
	this->thiefSprite.setPosition(390, 290);
}

void Player::initAnimations()
{
	// bat dau dem gio
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	checkSlowly = false;
	moveSpeed = 1.0f;
}

Player::~Player()
{
}

//sf::Vector2f Player::getCurrentPosition(const sf::Drawable& drawable)
//{
//	if (const sf::Transformable* transformable = dynamic_cast<const sf::Transformable*>(&drawable)) {
//		// Kiểm tra xem drawable có thể biến đổi không (có thể lấy tọa độ không)
//		return transformable->getPosition();
//	}
//	else {
//		// Nếu không thể lấy tọa độ, trả về một giá trị mặc định hoặc ném một ngoại lệ.
//		// Ở đây, chúng ta trả về (0, 0) làm giá trị mặc định.
//		return sf::Vector2f(0, 0);
//	}
//}

bool Player::getCheckSlowly()
{
	return this->checkSlowly;
}

short Player::getanimState()
{
	return this->animState;
}

float Player::getMoveSpeed()
{
	return moveSpeed;
}

sf::Vector2f Player::getThiefPosition()
{
	return this->thiefSprite.getPosition();
}

sf::FloatRect Player::getThiefGlobalBounds()
{
	return thiefSprite.getGlobalBounds();
}

void Player::setPlayerPosition(float x, float y)
{
	this->thiefSprite.move(x, y);
}

void Player::checkRange()
{
	float x = this->thiefSprite.getPosition().x; // toa do X cua goc trai tren
	float y = this->thiefSprite.getPosition().y; // toa do Y cua goc trai tren
	float x1 = this->thiefSprite.getGlobalBounds().width; // toa do X cua goc phai duoi
	float y1 = this->thiefSprite.getGlobalBounds().height; // toa do Y cua goc phai duoi

	// truong hop vuot qua le trai
	if (x < 0)
	{
		thiefSprite.setPosition(0, y);
	}
	// truong hop vuot qua le tren
	else if (y < 0)
	{
		thiefSprite.setPosition(x, 0);
	}
	// truong hop vuot qua le phai
	else if (x + x1 > screenWidth)
	{
		thiefSprite.setPosition(screenWidth - x1, y);
	}
	// truong hop vuot qua le duoi
	else if (y + y1 > screenHight)
	{
		thiefSprite.setPosition(x, screenHight - y1);
	}
}

void Player::updateMovement()
{	
	// -- kiem tra nut shift -- //
	// truong hop giu nut shift (di cham)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift))
	{
		moveSpeed = 0.5f;
		this->checkSlowly = true; // xac nhan di cham
	}
	// truong hop khong giu nut shift (di binh thuong)
	else
	{
		moveSpeed = 1.0f;
		this->checkSlowly = false; // xac nhan di binh thuong
	}

	// cap nhat trang thai nhan vat
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->thiefSprite.move(-moveSpeed, 0.f); // di chuyen toa do anh
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->thiefSprite.move(moveSpeed, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		this->thiefSprite.move(0.f, -moveSpeed);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->thiefSprite.move(0.f, moveSpeed);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_DOWN;
	}
	else
	{
		this->animState = PLAYER_ANIMATION_STATES::IDLE;
	}
	checkRange();
}

void Player::updateAnimation()
{
	// thuc hien thay doi hinh anh nhan vat qua moi 0.13 giay (tao chuyen dong)
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.13f)
	{
		// truong hop nhan vat dung im
		if (this->animState == PLAYER_ANIMATION_STATES::IDLE) 
		{
			this->currentFrame.left = 0.f;
			this->animationTimer.restart();
			this->thiefSprite.setTextureRect(this->currentFrame);
		}

		// truong hop nhan vat di xuong
		else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_DOWN)
		{
			this->currentFrame.top = 150.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 400.f)
				this->currentFrame.left = 0;
		}

		//truong hop nhan vat di sang trai
		else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
		{
			this->currentFrame.top = 300.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 400.f)
				this->currentFrame.left = 0;
		}

		//truong hop nhan vat di sang phai
		else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
		{
			this->currentFrame.top = 450.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 400.f)
				this->currentFrame.left = 0;
		}

		//truong hop nhan vat di len
		else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_UP)
		{
			this->currentFrame.top = 600.f;
			this->currentFrame.left += 100.f;
			if (this->currentFrame.left >= 400.f)
				this->currentFrame.left = 0;
		}

		// dat lai thoi gian
		this->animationTimer.restart();
		// gan hinh cho nhan vat
		this->thiefSprite.setTextureRect(this->currentFrame);
	}
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->thiefSprite);
}
