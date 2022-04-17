#pragma once
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Database.h"

/*struct CheckPoint {
	int iPos;
	int jPos;
	bool isActivated;
	CheckPoint(int i, int j) {
		iPos = i;
		jPos = j;
		isActivated = false;
	}
	CheckPoint() {
		iPos = 0;
		jPos = 0;
		isActivated = false;
	}
};*/

class Scene {
protected:
//	int height = 0;
//	int width = 0;
	int scrW, scrH;
	sf::Sprite background;
	float currentDiamond = 0, currentObelisk = 0, currentKey = 0, currentCeilingTrap = 0, currentLightningTrap = 0, currentSaw = 0;
	sf::Sound backgroundMus;
	
public:
	int allCoins = 0, score = 0, bestScore = 0;
	float currentFireTrap = 0;
	int levelNumber;
	//sf::Sprite tileset, coin, healPotion, tileset1;
	bool levelCompleted = false;
	sf::Sprite tileset, coin, healPotion, obelisk, door, key, saw, fireTrap, lightningTrap, ceilingTrap;
	sf::Text doorText;
	int allKeys = 3;
	sf::FloatRect spawnPoint;
//	CheckPoint checkpoints[5];
	std::vector<std::string> mainTilemap, copyTilemap; //for colliders mainly
	float offsetX = 0, offsetY = 0;
	Scene(sf::FloatRect spawn) {
		spawnPoint = spawn;
		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;
		background.setTexture(DATABASE.textures.at(11));
		//background.setTextureRect(sf::IntRect(0,200,1920,620));
		background.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / background.getGlobalBounds().width / 1, sf::VideoMode::getDesktopMode().height / background.getGlobalBounds().height / 1));

		backgroundMus.setBuffer(DATABASE.soundBuffers.at(8));
		backgroundMus.setVolume(Volume);
		
	}
	~Scene() {
	//	delete[] checkpoints;
	//	delete[] mainTilemap;
	}
	virtual void Update(float time) = 0;
	virtual void Restart() = 0;
	virtual void DrawMap() = 0;


	void SaveScore() {
		
		if (score > bestScore) {
			std::string file = "Saves/Level" + std::to_string(levelNumber) + ".bin";
			std::ofstream saveFile(file, std::ios::out | std::ios::binary);
			if (saveFile) {
				saveFile.write((char*)&score, sizeof(score));
				saveFile.close();
			}
			
			
		}
	}
	void LoadScore() {
		std::string file = "Saves/Level" + std::to_string(levelNumber) + ".bin";
		std::ifstream loadFile(file, std::ios::out | std::ios::binary);
		if (loadFile) {
			loadFile.read((char*)&bestScore, sizeof(score));
			loadFile.close();
		}
	}
};