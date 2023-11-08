#pragma once
#include "stdafx.h"
#include "gameConfig.h"
#include <string.h>
#include <fstream>
#include "Record.h"

class Record
{
private:
	sf::RenderWindow window; // cua so cuar game
	sf::Texture backgroundTexture; // tao doi tuong luu anh
	sf::RectangleShape background; // background la hinh vuong
	sf::Font font; // tao font
	sf::Event ev; // bien bat su kien
	sf::Clock recordTime;
	std::vector<float> recordTimeList;
	std::vector<std::string> userName;
	sf::RectangleShape recordFrame;
	std::ifstream inFile;
	
	void initWindow();
	void initBackGround();
	void initFont();
	void initRecordTime();
	void initRecordFrame();
	void initRecordTimeList();
public:
	Record();
	~Record();

	void merge(std::vector<float>& arr, int left, int middle, int right); // Ham merge hai mang con da sap xep thanh 1 mang da sap xep
	void mergeSort(std::vector<float>& arr, int left, int right); // Ham sap xep vector su dung merge sort
	void sortRecord();
	//update
	void update();
	//render
	void renderBackGround();
	void renderFrame();
	void renderTime();
	void renderName();
	void render();

	void runRecord();
};

