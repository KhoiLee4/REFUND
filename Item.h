#pragma once

class Item
{
private:
    std::vector<sf::Texture> itemTextures;
    sf::Sprite currentSprite;
    bool keyPressed = false; 
    int currentItem = 0;

    //sf::Clock debounceTime;
    void initcurrentSprite();
    void initTexture();
    void initSprite();
public:
    Item();
    virtual ~Item();
    
    //Functions
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

