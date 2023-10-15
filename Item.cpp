#include "stdafx.h"
#include "Item.h"

void Item::initTexture()
{
    for (int i = 1; i <= 6; i++) 
    {
        sf::Texture texture;
        
        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png")) {
            this->itemTextures.push_back(texture);
        }
        else {
            std::cerr << "Failed to load item" << i << ".png" << std::endl;
        }
    }
}
void Item::initcurrentSprite()
{
    this->currentSprite.setPosition(100, 200);
    this->currentSprite.setTexture(this->itemTextures[currentItem]);
}

void Item::initSprite()
{
    this->initcurrentSprite();
}
Item::Item()
{
	this->initTexture();
    this->initSprite();
}
Item::~Item()
{
}
void Item::update()
{
    //float thresholdDistance = 1.0f; // Khoảng cách tối thiểu để xem là đã đến gần
    //int eKeyPressCount = 0;
    //std::cout << player->getCurrentPosition().x << ' ' << player->getCurrentPosition().y;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) && !this->keyPressed)
        {
            currentItem++;
            if (currentItem < itemTextures.size())
            {
                this->currentSprite.setTexture(this->itemTextures[currentItem]);
                //eKeyPressCount++;
            }
            this->keyPressed = true;
        }
    //if (sf::Event::KeyReleased && sf::Keyboard::E) {
    //    // Thiết lập lại biến khi phím "E" được nhãn
    //    this->keyPressed1 = false;
    //}
    //std::cout << eKeyPressCount;
}
void Item::render(sf::RenderTarget& target)
{
    target.draw(this->currentSprite);
}

