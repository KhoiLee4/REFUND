#include "stdafx.h"
#include "Noise.h"

void Noise::initNoiseBar()
{
    noiseBarLayer.setSize(sf::Vector2f(600, 30));
    noiseBarLayer.setPosition(20, 20);
    noiseBarLayer.setFillColor(sf::Color::White);

    noiseBar.setSize(sf::Vector2f(0, 30));
    noiseBar.setPosition(20, 20);
    noiseBar.setFillColor(sf::Color::Green);
}

void Noise::initNoiseIndex()
{
    this->currentNoise = 0.f;
    this->maxNoise = 200.f;
}

Noise::Noise()
{
    this->initNoiseBar();
    this->initNoiseIndex();
}

Noise::~Noise()
{
}

bool Noise::checkNoiseMax()
{
    if (this->currentNoise >= this->maxNoise) return true;
    else return false;
}

void Noise::updateNoiseBar()
{
    noiseBar.setSize(sf::Vector2f(currentNoise * 3, 30));
}

void Noise::setNoiseIndex(float index)
{
    this->currentNoise += index;
}

void Noise::update()
{
    this->updateNoiseBar();
}

void Noise::render(sf::RenderTarget& target)
{
    target.draw(this->noiseBarLayer);
    target.draw(this->noiseBar);
}
