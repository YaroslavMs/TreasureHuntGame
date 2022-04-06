#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Database.h"

class Scene {
protected:
	int height = 0;
	int width = 0;
	int scrW, scrH;
	sf::Sprite background;
	
	
public:
	sf::Sprite tileset;
	sf::FloatRect spawnPoint;
	std::string* mainTilemap; //for colliders mainly
	float offsetX = 0, offsetY = 0;
	Scene(sf::FloatRect spawn) {
		spawnPoint = spawn;
		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;
		background.setTexture(DATABASE.textures.at(0));
		background.setTextureRect(sf::IntRect(1160, 81, 1294 - 1160, 190 - 81));
		background.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / background.getGlobalBounds().width / 10, sf::VideoMode::getDesktopMode().height / background.getGlobalBounds().height / 6));
	}
	virtual void Update(float time) = 0;
	virtual void DrawMap() = 0;

};