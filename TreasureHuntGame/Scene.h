#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.h"
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
	int allCoins = 0, score = 0;
	float currentFireTrap = 0;
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

};