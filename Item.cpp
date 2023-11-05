#include "Item.h"

void Item::initTexture()
{
    // lay hinh tu data vao
    for (int i = 1; i <= 6; i++) 
    {
        sf::Texture texture; // tao doi tuong luu anh do
        if (texture.loadFromFile("Data/Textures/Items/item" + std::to_string(i) + ".png"))
        {
            this->itemTextures.push_back(texture); // them vao cuoi (bat dau tu 0)
        }
        else
        {
            std::cerr << "Failed to load item " << i << ".png" << std::endl;
        }
    }

    sf::Texture texture; // tao doi tuong luu anh xe
    if (texture.loadFromFile("Data/Textures/Items/emptyCar.jpg")) {
        this->itemTextures.push_back(texture); 
    }
    else
    {
        std::cerr << "Failed to load item.png" << std::endl;
    }
}

void Item::initSprite()
{
    this->currentSprite.setPosition(100, 200); // vi tri xuat hien ban dau (noi lay do)
    this->currentSprite.setTexture(this->itemTextures[currentItem]); // gan hinh do hien tai
}

Item::Item()
{
	this->initTexture();
    this->initSprite();
    currentItem = 0;
    keyPressed = false;
}

Item::~Item()
{
}

sf::Vector2f Item::getItemPosition()
{
    return this->currentSprite.getPosition();
}

void Item::updateItem()
{
    // chuyen sang mon do ke tiep
    this->currentItem++;
    if (currentItem < itemTextures.size())
    {
        this->currentSprite.setTexture(this->itemTextures[currentItem]);
    }
}

void Item::update()
{
}

void Item::render(sf::RenderTarget& target)
{
    target.draw(this->currentSprite);
}

