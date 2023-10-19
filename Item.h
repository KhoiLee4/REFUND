#pragma once

class Item
{
private:
    bool keyPressed = false; 
    //sf::Clock debounceTime;
    void initcurrentSprite();
    void initTexture();
    void initSprite();
public:
    Item();
    virtual ~Item();

    std::vector<sf::Texture> itemTextures;
    sf::Sprite currentSprite;
    int currentItem = 0;

    //Functions
    sf::Vector2f getItemPosition();
    void updateItem();
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

