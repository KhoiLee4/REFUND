#pragma once
class ItemPick
{
private:
    bool keyPressed = false, eraseItem = true;
    //sf::Clock debounceTime;
    void initTexture();
    //void initSprite();
public:
    ItemPick();
    virtual ~ItemPick();

    std::vector<sf::Texture> itemTextures;
    sf::Sprite pickSprite;
    int pickItem = 0;

    //Functions
    void updateRestore();
    void updatePick();
    void update();
    void render(sf::RenderTarget& target);
    //Functions
};

