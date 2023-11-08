#pragma once

#include "gameConfig.h"
#include "stdafx.h"

/*
## Class Noise ##
- thuc hien cac cong viec lien quan den tieng on
	+ kiem tra 
	+ thay doi
	+ hien thi
*/

class Noise
{
private:
	sf::RectangleShape noiseBar; // thanh tieng on
	sf::RectangleShape noiseBarLayer; // khung tieng on
	float currentNoise; // luong tieng on
	float maxNoise; // luong tieng on toi da

	void initNoiseBar(); // khoi tao thanh tieng on
	void initNoiseIndex(); // khoi tao gia tri tieng on

public:
	Noise();
	virtual ~Noise();

	//Functions
	bool checkNoiseMax(); // kiem tra luong tieng on da toi da chua
	void updateNoiseBar(); // cap nhat thanh tieng on
	void setNoiseIndex(float index); // thay doi luong tieng on
	void update(); // cap nhat tieng on
	void render(sf::RenderTarget& target); // ve thanh tieng on

};

