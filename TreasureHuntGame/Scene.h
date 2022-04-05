#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Object.h"

class Scene {
protected:
	int height = 0;
	int width = 0;
	
public:
	sf::Sprite tileset;
	sf::FloatRect spawnPoint;
	std::string* mainTilemap; //for colliders mainly
	float offsetX = 0, offsetY = 0;
	Scene(sf::FloatRect spawn) {
		spawnPoint = spawn;
	}
	virtual void Update(float time) = 0;
	virtual void DrawMap() = 0;

};