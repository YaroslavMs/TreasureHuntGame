#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Database.h"
#include "Sprite.h"
#include "Player.h"


class UI {
	sf::Sprite heartBorder, heart;
	int scrW, scrH;


public:
	UI() {
		heartBorder.setTexture(DATABASE.textures.at(9));
		heart.setTexture(DATABASE.textures.at(10));
		heart.setScale(sf::Vector2f(4, 4));
		heartBorder.setScale(sf::Vector2f(4, 4));
		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;
	}
	void Update() {

	}
	void Draw(Player player) {
		
		for (int i = 0; i < 3; i++)
		{
			heartBorder.setPosition(50 + i * 80, 50);
			window.Renderer.draw(heartBorder);
		}
		for (int i = 0; i < player.lives; i++)
		{
			heart.setPosition(50 + i * 80, 50);
			window.Renderer.draw(heart);
		}
	}





};
