#pragma once

enum HOST_ANIMATION_STATES { SLEEP, WAKEUP};
class Host
{
	sf::Sprite hostSprite;
	sf::Texture textureSheet;
	sf::Clock animationTimer;
	//Animation
	short animState;
	sf::IntRect currentFrame;
	//Movement

	//Core
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
public:
	Host();
	virtual ~Host();

	//Functions
	sf::Vector2f getHostPosition();
	void updateVariables();
	void updateAnimation();
	void update();
	void render(sf::RenderTarget& target);
	//Functions
};

