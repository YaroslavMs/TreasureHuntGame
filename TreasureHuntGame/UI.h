#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Database.h"
#include "Sprite.h"
#include "Player.h"


class UI {
	sf::Sprite heartBorder, heart, diamond, key;
	std::string amountOfCoins = "", keyString = "";
	sf::Text coinsText, keyText;
	int scrW, scrH;
	float currentFrame = 0, currentKey = 0;

public:
	UI() {
		coinsText.setFont(DATABASE.fonts.at(0));
		coinsText.setCharacterSize(40);
		coinsText.setFillColor(sf::Color::Yellow);
		coinsText.setOutlineColor(sf::Color::Black);
		coinsText.setOutlineThickness(2);
		coinsText.setPosition(sf::Vector2f(120, 165));
		keyText.setFont(DATABASE.fonts.at(0));
		keyText.setCharacterSize(40);
		keyText.setFillColor(sf::Color::Yellow);
		keyText.setOutlineColor(sf::Color::Black);
		keyText.setOutlineThickness(2);
		keyText.setPosition(sf::Vector2f(120, 290));
		heartBorder.setTexture(DATABASE.textures.at(9));
		heart.setTexture(DATABASE.textures.at(10));
		diamond.setTexture(DATABASE.textures.at(12));
		key.setTexture(DATABASE.textures.at(16));
		heart.setScale(sf::Vector2f(4, 4));
		heartBorder.setScale(sf::Vector2f(4, 4));
		diamond.setScale(sf::Vector2f(6, 6));
		key.setScale(sf::Vector2f(3, 3));
		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;
	}
	void Update(float time) {
		currentFrame += time * 0.003;
		currentKey += time * 0.003;
	}
	void Draw(Player player) {
		amountOfCoins = player.coinsCollected <= 0 ? "" : std::to_string(player.coinsCollected);
		keyString = std::to_string(player.keysFound) + " / " + std::to_string(3) + " keys found.";
		coinsText.setString(amountOfCoins);
		keyText.setString(keyString);
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
		if (currentKey >= 12)
			currentKey = 0;
		key.setTextureRect(sf::IntRect(10 + (int)currentKey * 32, 0, 12, 32));
		key.setPosition(50, 270);
		window.Renderer.draw(key);
		window.Renderer.draw(coinsText);
		window.Renderer.draw(keyText);
		window.Renderer.draw(diamond);
		
	}





};
