#pragma once

class Item
{
private:
    std::vector<sf::Texture> itemTextures;
    sf::Sprite  pickSprite, currentSprite;
    bool keyPressed = false, keyPressed1 = false;
    //int currentItem=0, pickItem=0;
    //sf::Clock debounceTime;
    void initcurrentSprite();
    void initpickSprite();
    void initTexture();
    void initSprite();
public:
    Item();
    virtual ~Item();
    
    //Functions
    //void updatePick();
    void pickUpdate();
    void currentUpdate();
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

