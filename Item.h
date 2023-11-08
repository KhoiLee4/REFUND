#pragma once

#include "gameConfig.h"
#include "stdafx.h"

#include <random>

/*
## Class Item ##
- thuc hien cac cong viec lien quan den do vat tren xe tai
    + hien thi
    + thay doi

*/


class Item
{
private:
    std::vector<sf::Texture> itemTextures; // doi tuong luu anh
    sf::Sprite currentSprite; // mon do in ra mang hinh
    std::vector<sf::Texture> carTextures; // doi tuong luu anh
    sf::Sprite carSprite; // mon do in ra mang hinh
    int currentItem; // vi tri mon do hien tai
    bool keyPressed; 

    //sf::Clock debounceTime;
    //void initcurrentSprite();
    void initTexture(); // khoi tao hinh anh
    void initSprite(); // khoi tao doi tuong de in ra mang hinh

public:
    Item();
    virtual ~Item();

    //std::map<int, sf::Texture> itemTextures;
    //Functions
    sf::Vector2f getItemPosition(); // tra ve vi tri mon do tren xe tai
    void moveItem(float x, float y);
    
    void updateItem(); // cap nhat lai do tren xe tai
    void update();
    void render(sf::RenderTarget& target); // ve do tren xe tai

};

