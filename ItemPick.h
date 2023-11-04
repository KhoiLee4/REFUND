#pragma once
class ItemPick
{
private:
    std::vector<sf::Texture> itemTextures;
    bool keyPressed = false, eraseItem = true;
    //sf::Clock debounceTime;
    void initTexture();
    //void initSprite();
public:
    ItemPick();
    virtual ~ItemPick();

    sf::Sprite pickSprite;
    int pickItem = 0;

    //Functions
    void updateRestore();
    void updatePick();
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

