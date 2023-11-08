#include "Record.h"

void Record::initWindow()
{
	//Create game window
	this->window.create(sf::VideoMode(screenWidth, screenHight), "Refund", sf::Style::Close | sf::Style::Titlebar);
	//Set frame rate
	this->window.setFramerateLimit(144);
}

void Record::initBackGround()
{
	// tao backgruond
	backgroundTexture.loadFromFile("Data/Textures/Background/Record.png"); // nap hinh vao
	background.setTexture(&backgroundTexture); // gan backgroundTexture cho background (lay backgroundTexture lam nen)
	background.setSize(sf::Vector2f(screenWidth, screenHight)); // dat kich thuot cho back ground
}

void Record::initFont()
{
	// Tao 1 doi tuong van ban de hien thi thoi gian
	if (!font.loadFromFile("Data/Textures/Font/PixelGameFont.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
	}
}

void Record::initRecordTime()
{
	this->recordTime.restart();
}

void Record::initRecordFrame()
{
	recordFrame.setSize(sf::Vector2f(500, 500));
	recordFrame.setPosition(10, 10);
	recordFrame.setFillColor(sf::Color::Cyan);
}

void Record::initRecordTimeList()
{
	inFile.open("Record.txt");

	// Kiem tra xem tep da mo duoc chua
	if (!inFile.is_open()) {
		std::cerr << "Failed to load file" << std::endl;
	}

	std::string name;
	float number;

	while (std::getline(inFile, name)) {
		if (inFile >> number) {
			recordTimeList.push_back(number);
		}
		else {
			std::cerr << "Failed to load" << std::endl;
		}

		// bo qua dong thua
		std::string discard;
		std::getline(inFile, discard);
	}

	inFile.close();
}

Record::Record()
{
	initWindow();
	initBackGround();
	initFont();
	initRecordTime();
	initRecordTimeList();
	initRecordFrame();
}

Record::~Record()
{
}

void Record::merge(std::vector<float>& arr, int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;
	// Tạo các mảng tạm thời
	std::vector<float> L(n1);
	std::vector<float> R(n2);
	// Sao chép dữ liệu vào các mảng tạm thời L[] và R[]
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[middle + 1 + j];
	}
	// Merge các mảng tạm thời thành mảng chính arr[]
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// Sao chép các phần tử còn lại của L[] (nếu có)
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	// Sao chép các phần tử còn lại của R[] (nếu có)
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void Record::mergeSort(std::vector<float>& arr, int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;  // Tim diem giua cua mang
		// Sap xep phan dau va phan cuoi
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);  // Merge hai mang con da sap xep
	}
}

void Record::sortRecord()
{
	mergeSort(recordTimeList, 0, recordTimeList.size() - 1);
}

void Record::update()
{
	while (this->window.pollEvent(this->ev))
		//if (this->window.pollEvent(this->ev))
	{
		// truong hop bam tat cua so
		if (this->ev.type == sf::Event::Closed)
			this->window.close(); // dong cua so

		// truong hop bam nut ESC
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close(); // dong cua so
	}
	sortRecord();
}

void Record::renderBackGround()
{
	window.draw(background);
}

void Record::renderFrame()
{
	window.draw(this->recordFrame);
}

void Record::renderTime()
{
	for (int i = 0; i < userName.size(); i++)
	{
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(24);
		text.setString(std::to_string(recordTimeList[i]));
		text.setFillColor(sf::Color::White);
		text.setPosition(40, (i+1) * 2);

		window.draw(text);
	}
}

void Record::renderName()
{
	for (int i = 0; i < userName.size(); i++)
	{
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(24);
		text.setString(userName[i]);
		text.setFillColor(sf::Color::White);
		text.setPosition(20, (i+1) * 2);

		window.draw(text);
	}
}

void Record::render()
{
	renderBackGround();
	renderFrame();
	renderName();
	renderTime();
}

void Record::runRecord()
{
	// bat dau
	while (window.isOpen())
	{
		update();
		render();
	}
}
