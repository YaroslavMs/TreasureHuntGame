#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Database.h"


class MainMenu {

	sf::Sprite background, button;
	sf::Text text[3], name;

public:
	MainMenu() {
		background.setTexture(DATABASE.textures.at(0));
		background.setTextureRect(sf::IntRect(1160, 81, 1294 - 1160, 190 - 81));
		background.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / background.getGlobalBounds().width, sf::VideoMode::getDesktopMode().height / background.getGlobalBounds().height));
		this->button.setTexture(DATABASE.textures.at(2));
		this->button.setTextureRect(sf::IntRect(0, 0, 200, 60));
		this->button.setScale(2, 1.5);
		text[0].setString("Play");
		text[1].setString("Options");
		text[2].setString("Quit");
		for (int i = 0; i < 3; i++) {
			text[i].setFont(DATABASE.fonts.at(0));
			text[i].setFillColor(sf::Color::Red);
			text[i].setCharacterSize(80);
			text[i].setOutlineColor(sf::Color::White);
			text[i].setOutlineThickness(2);
			text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height / 2);
		}
		name.setString("Treasure  Hunt");
		name.setFillColor(sf::Color::Red);
		name.setOutlineColor(sf::Color::White);
		name.setOutlineThickness(5);
		name.setCharacterSize(200);
		name.setFont(DATABASE.fonts.at(0));
		name.setOrigin(name.getGlobalBounds().width / 2, name.getGlobalBounds().height / 2);
		name.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 200));
		for (int i = 1; i <= 3; i++)
			text[i - 1].setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 275 + 180 * i));


	}
	int UpdateMenu() {
		window.Renderer.draw(background);
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		for (int i = 1; i <= 3; i++) {

			button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 100 * 2, 250 + 180 * i));
			if (CheckCollision(button.getGlobalBounds(), mousePos)) {
				button.setColor(sf::Color(100, 0, 0, 255));
			}
			else button.setColor(sf::Color::White);
			window.Renderer.draw(button);
			window.Renderer.draw(text[i - 1]);
		}
		window.Renderer.draw(name);
		return 0;
	}

	bool CheckCollision(sf::FloatRect rect, sf::Vector2i mousePos) {
		if (mousePos.x < rect.left)
			return false;
		if (mousePos.y < rect.top)
			return false;
		if (mousePos.x > rect.left + rect.width)
			return false;
		if (mousePos.y > rect.top + rect.height)
			return false;
		return true;
	}

	int MouseClicked(sf::Mouse mouse) {
		for (int i = 1; i <= 3; i++) {
			button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 100 * 2, 250 + 180 * i));
			if ((CheckCollision(button.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
				return i;
			}
		}
	}


};