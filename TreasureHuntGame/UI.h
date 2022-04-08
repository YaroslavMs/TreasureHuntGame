#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Database.h"
#include "Sprite.h"
#include "Player.h"


class UI {
	sf::Sprite heartBorder, heart, diamond;
	std::string amountOfCoins = "";
	sf::Text coinsText;
	int scrW, scrH;
	float currentFrame = 0;

public:
	UI() {
		coinsText.setFont(DATABASE.fonts.at(0));
		coinsText.setCharacterSize(60);
		coinsText.setFillColor(sf::Color::Blue);
		coinsText.setOutlineColor(sf::Color::Blue);
		coinsText.setOutlineThickness(3);
		coinsText.setPosition(sf::Vector2f(120, 150));
		heartBorder.setTexture(DATABASE.textures.at(9));
		heart.setTexture(DATABASE.textures.at(10));
		diamond.setTexture(DATABASE.textures.at(12));
		heart.setScale(sf::Vector2f(4, 4));
		heartBorder.setScale(sf::Vector2f(4, 4));
		diamond.setScale(sf::Vector2f(6, 6));
		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;
	}
	void Update(float time) {
		currentFrame += time * 0.003;
	}
	void Draw(Player player) {
		amountOfCoins = player.coinsCollected <= 0 ? "" : std::to_string(player.coinsCollected);
		coinsText.setString(amountOfCoins);
		for (int i = 0; i < player.lives; i++)
		{
			heart.setPosition(50 + i * 80, 50);
			window.Renderer.draw(heart);
		}
		for (int i = 0; i < 5; i++)
		{
			heartBorder.setPosition(50 + i * 80, 50);
			window.Renderer.draw(heartBorder);
		}
		if (currentFrame >= 5)
			currentFrame = 0;
		diamond.setTextureRect(sf::IntRect(0 + 8 * (int)currentFrame, 0, 8, 9));
		diamond.setPosition(50, 160);
		window.Renderer.draw(coinsText);
		window.Renderer.draw(diamond);
		
	}





};
