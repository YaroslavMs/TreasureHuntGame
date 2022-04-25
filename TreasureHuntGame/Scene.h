#pragma once
#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Database.h"

class Scene {
protected:
	int scrW, scrH;
	sf::Sprite background;
	float currentDiamond = 0, currentObelisk = 0, currentKey = 0, currentCeilingTrap = 0, currentLightningTrap = 0, currentSaw = 0;
	sf::Sound backgroundMus;
	
public:
	int allCoins = 0, score = 0, bestScore = 0;
	float currentFireTrap = 0;
	int levelNumber, W = 0, H = 0;
	bool levelCompleted = false;
	sf::Sprite tileset, coin, healPotion, obelisk, door, key, saw, fireTrap, lightningTrap, ceilingTrap, speedBoost, gravityBoost, shieldBoost;
	sf::Text doorText;
	int allKeys = 3;
	sf::FloatRect spawnPoint;
	std::vector<std::string> mainTilemap, copyTilemap; //for colliders mainly
	float offsetX = 0, offsetY = 0;
	Scene(sf::FloatRect spawn) {
		spawnPoint = spawn;
		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;
		background.setTexture(DATABASE.textures.at(11));
		background.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / background.getGlobalBounds().width / 1, sf::VideoMode::getDesktopMode().height / background.getGlobalBounds().height / 1));

		backgroundMus.setBuffer(DATABASE.soundBuffers.at(8));
		backgroundMus.setVolume(Volume);
		
	}
	virtual void Update(float time) = 0;
	virtual void Restart() = 0;
	virtual void DrawMap() = 0;


	void SaveScore() {
		
		if (score > bestScore) {
			bestScore = score;
			std::string file = "Saves/Level" + std::to_string(levelNumber) + ".dat";
			std::ofstream saveFile(file, std::ios::out | std::ios::binary);
			if (saveFile) {
				saveFile.write((char*)&score, sizeof(score));
				saveFile.close();
			}
			
			
		}
	}
	void LoadScore() {
		std::string file = "Saves/Level" + std::to_string(levelNumber) + ".dat";
		std::ifstream loadFile(file, std::ios::out | std::ios::binary);
		if (loadFile) {
			loadFile.read((char*)&bestScore, sizeof(score));
			loadFile.close();
		}
	}
};