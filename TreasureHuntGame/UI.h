#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Scene.h"
#include "Database.h"
#include "Player.h"


class UI {
	//Basic UI
	sf::Sprite heartBorder, heart, diamond, key;
	std::string amountOfCoins = "", keyString = "", timeString = "";
	sf::Text coinsText, keyText;
	float currentFrame = 0, currentKey = 0;
	sf::Sprite speedBoost, gravityBoost;
	sf::Text timeLeft;

	//Pause menu
	sf::Sprite background, button;
	sf::Text text[4];

	//DeathPanel
	sf::Text YouDied[2];
	sf::Sprite Panel;
	sf::Texture emtyTexture;

	//WinPanel
	sf::Text winButtonsT[3], youWinText;
	sf::Sprite winPanel, Star, winPanelButton, winButton;

	int scrW, scrH;
	sf::Sound clickSound;
public:
	bool gamePaused = false;
	UI() {
		clickSound.setBuffer(DATABASE.soundBuffers.at(6));
		clickSound.setVolume(Volume);

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
		timeLeft.setFont(DATABASE.fonts.at(0));
		timeLeft.setCharacterSize(40);
		timeLeft.setFillColor(sf::Color::Yellow);
		timeLeft.setOutlineColor(sf::Color::Black);
		timeLeft.setOutlineThickness(2);
		heartBorder.setTexture(DATABASE.textures.at(9));
		heart.setTexture(DATABASE.textures.at(10));
		diamond.setTexture(DATABASE.textures.at(12));
		key.setTexture(DATABASE.textures.at(16));
		heart.setScale(sf::Vector2f(4, 4));
		heartBorder.setScale(sf::Vector2f(4, 4));
		diamond.setScale(sf::Vector2f(6, 6));
		key.setScale(sf::Vector2f(3, 3));
		speedBoost.setTexture(DATABASE.textures.at(25));
		speedBoost.setTextureRect(sf::IntRect(89, 64, 6, 8));
		speedBoost.setScale(sf::Vector2f(sizeMultiplier * 3, sizeMultiplier * 3));
		gravityBoost.setTexture(DATABASE.textures.at(25));
		gravityBoost.setTextureRect(sf::IntRect(73, 64, 7, 8));
		gravityBoost.setScale(sf::Vector2f(sizeMultiplier * 3, sizeMultiplier * 3));

		scrW = sf::VideoMode::getDesktopMode().width;
		scrH = sf::VideoMode::getDesktopMode().height;




		background.setTexture(DATABASE.textures.at(0));
		background.setTextureRect(sf::IntRect(1160, 81, 1294 - 1160, 190 - 81));
		background.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / background.getGlobalBounds().width, sf::VideoMode::getDesktopMode().height / background.getGlobalBounds().height));
		button.setTexture(DATABASE.textures.at(2));
		button.setTextureRect(sf::IntRect(0, 0, 200, 60));
		button.setScale(2, 1.5);

		text[0].setString("Pause");
		text[0].setFillColor(sf::Color::Red);
		text[0].setOutlineColor(sf::Color::White);
		text[0].setOutlineThickness(5);
		text[0].setCharacterSize(200);
		text[0].setFont(DATABASE.fonts.at(0));
		text[0].setOrigin(text[0].getGlobalBounds().width / 2, text[0].getGlobalBounds().height / 2);
		text[0].setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 200));
		text[1].setString("Continue");
		text[2].setString("Restart");
		text[3].setString("Main menu");
		for (int i = 1; i < 4; i++) {
			text[i].setFont(DATABASE.fonts.at(0));
			text[i].setFillColor(sf::Color::Red);
			text[i].setCharacterSize(80);
			text[i].setOutlineColor(sf::Color::White);
			text[i].setOutlineThickness(2);
			text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height / 2);
		}
		for (int i = 2; i <= 4; i++)
			text[i - 1].setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 175 + 180 * i));

		YouDied[0].setString("You Died");
		YouDied[0].setFillColor(sf::Color::Red);
		YouDied[0].setOutlineColor(sf::Color::Black);
		YouDied[0].setOutlineThickness(10);
		YouDied[0].setCharacterSize(280);
		YouDied[0].setFont(DATABASE.fonts.at(0));
		YouDied[0].setOrigin(YouDied[0].getGlobalBounds().width / 2, YouDied[0].getGlobalBounds().height / 2);
		YouDied[0].setPosition(sf::Vector2f(window.width / 2, window.height / 2 - 100));

		YouDied[1].setString("Respawn");
		YouDied[1].setFillColor(sf::Color::Black);
		YouDied[1].setOutlineColor(sf::Color::Red);
		YouDied[1].setOutlineThickness(2);
		YouDied[1].setCharacterSize(80);
		YouDied[1].setFont(DATABASE.fonts.at(0));
		YouDied[1].setOrigin(YouDied[1].getGlobalBounds().width / 2, YouDied[1].getGlobalBounds().height / 2);
		YouDied[1].setPosition(sf::Vector2f(window.width / 2, window.height / 2 + 225));
		Panel.setTexture(DATABASE.textures.at(2));
		Panel.setPosition(0, 0);
		Panel.setScale(sf::Vector2f(scrW / Panel.getGlobalBounds().width, scrH / Panel.getGlobalBounds().height));
		Panel.setColor(sf::Color(225, 0, 0, 60));


		winPanel.setTexture(DATABASE.textures.at(2));
		winPanel.setPosition(scrW / 4, scrH / 4);
		winPanel.setScale(sf::Vector2f(scrW / winPanel.getGlobalBounds().width / 2, scrH / winPanel.getGlobalBounds().height / 2));
		winPanel.setColor(sf::Color(60, 30, 0));
		youWinText.setString("Level Completed");
		youWinText.setFillColor(sf::Color::Red);
		youWinText.setOutlineColor(sf::Color::White);
		youWinText.setOutlineThickness(2);
		youWinText.setCharacterSize(120);
		youWinText.setFont(DATABASE.fonts.at(0));
		youWinText.setOrigin(youWinText.getGlobalBounds().width / 2, youWinText.getGlobalBounds().height / 2);
		youWinText.setPosition(sf::Vector2f(window.width / 2, window.height / 4 + 25));
		Star.setTexture(DATABASE.textures.at(21));
		Star.setTextureRect(sf::IntRect(6, 6, 20, 22));
		Star.setOrigin(Star.getGlobalBounds().width / 2, Star.getGlobalBounds().height / 2);
		Star.setScale(sf::Vector2f(5, 5));
		winButtonsT[0].setString("To Main menu");
		winButtonsT[1].setString("Restart");
		winButtonsT[2].setString("Next level");
		for (int i = 0; i < 3; i++) {
			winButtonsT[i].setFont(DATABASE.fonts.at(0));
			winButtonsT[i].setFillColor(sf::Color::Red);
			winButtonsT[i].setCharacterSize(50);
			winButtonsT[i].setOutlineColor(sf::Color::White);
			winButtonsT[i].setOutlineThickness(2);
			winButtonsT[i].setOrigin(winButtonsT[i].getGlobalBounds().width / 2, winButtonsT[i].getGlobalBounds().height / 2);
		}
		winButton.setTexture(DATABASE.textures.at(2));
		winButton.setColor(sf::Color(160, 80, 0));
		winButton.setTextureRect(sf::IntRect(0, 0, 200, 60));
		winButton.setScale(1.5, 1.5);



	}
	void UpdateVolume() {
		clickSound.setVolume(Volume);
	}

	void Update(float time) {
		currentFrame += time * 0.003;
		currentKey += time * 0.003;
	}
	void Draw(Player player) {
	//	WinMenu();

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
		if (player.speedBoostTime > 0) {
			speedBoost.setPosition(50, 380);
			timeString = std::to_string(player.speedBoostTime).substr(0, 3);
			timeLeft.setString(timeString);
			timeLeft.setPosition(sf::Vector2f(120, 390));
			window.Renderer.draw(speedBoost);
			window.Renderer.draw(timeLeft);
		}
		if (player.gravityBoostTime > 0) {
			gravityBoost.setPosition(50, 490);
			timeString = std::to_string(player.gravityBoostTime).substr(0, 3);
			timeLeft.setString(timeString);
			timeLeft.setPosition(sf::Vector2f(120, 500));
			window.Renderer.draw(gravityBoost);
			window.Renderer.draw(timeLeft);
		}
		window.Renderer.draw(key);
		window.Renderer.draw(coinsText);
		window.Renderer.draw(keyText);
		window.Renderer.draw(diamond);
		if (gamePaused)
			PauseMenu();
	}

	void PauseMenu() {
		window.Renderer.draw(background);
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		for (int i = 2; i <= 4; i++) {

			button.setPosition(sf::Vector2f(window.width / 2 - 100 * 2, 150 + 180 * i));
			if (CheckCollision(button.getGlobalBounds(), mousePos)) {
				button.setColor(sf::Color(100, 0, 0, 255));
			}
			else button.setColor(sf::Color::White);
			window.Renderer.draw(button);
			window.Renderer.draw(text[i - 1]);
		}
		window.Renderer.draw(text[0]);



	}
	void WinMenu(int stars) {
		window.Renderer.draw(winPanel);
		window.Renderer.draw(youWinText);
		for (int i = 0; i < 3; i++) {
			Star.setPosition(sf::Vector2f(scrW / 2 - scrW / 16 + scrW / 16 * i, scrH / 6 * 3));
			if (i >= stars)
				Star.setColor(sf::Color(0, 0, 0, 70));
			else Star.setColor(sf::Color::White);
			window.Renderer.draw(Star);
		}
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		for (int i = 0; i < 3; i++) {
			winButton.setPosition(sf::Vector2f(scrW / 2 - scrW / 6 + scrW / 6 * i - winButton.getGlobalBounds().width / 2, scrH / 2 + scrH / 5 - winButton.getGlobalBounds().height / 2));
			winButtonsT[i].setPosition(sf::Vector2f(scrW / 2 - scrW / 6 + scrW / 6 * i, scrH / 2 + scrH / 5));
			if (CheckCollision(winButton.getGlobalBounds(), mousePos)) {
				winButton.setColor(sf::Color(100, 0, 0, 255));
			}
			else winButton.setColor(sf::Color(160, 80, 0));
			window.Renderer.draw(winButton);
			window.Renderer.draw(winButtonsT[i]);
		}
	}
	void YouDiedMenu(Player player) {
		if (player.lives == 1) {
			YouDied[1].setString("Restart");
			YouDied[0].setString("You Lost");
			YouDied[1].setOrigin(YouDied[1].getGlobalBounds().width / 2, YouDied[1].getGlobalBounds().height / 2);
			YouDied[0].setOrigin(YouDied[0].getGlobalBounds().width / 2, YouDied[0].getGlobalBounds().height / 2);
		}
		else {
			YouDied[1].setString("Respawn");
			YouDied[0].setString("You Died");
			YouDied[1].setOrigin(YouDied[1].getGlobalBounds().width / 2, YouDied[1].getGlobalBounds().height / 2);
			YouDied[0].setOrigin(YouDied[0].getGlobalBounds().width / 2, YouDied[0].getGlobalBounds().height / 2);
		}
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		button.setPosition(sf::Vector2f(window.width / 2 - button.getGlobalBounds().width / 2, window.height / 2 + 200));
		if (CheckCollision(button.getGlobalBounds(), mousePos)) {
			button.setColor(sf::Color(100, 0, 0, 255));
		}
		else button.setColor(sf::Color::White);
		window.Renderer.draw(Panel);
		window.Renderer.draw(button);
		window.Renderer.draw(YouDied[1]);
		window.Renderer.draw(YouDied[0]);
	}
	bool RespawnButton(sf::Vector2i mousePos) {
		button.setPosition(sf::Vector2f(window.width / 2 - button.getGlobalBounds().width / 2, window.height / 2 + 200));
		if (CheckCollision(button.getGlobalBounds(), mousePos)) {
			clickSound.play();
			return true;
		}
		return false;
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
		for (int i = 2; i <= 4; i++) {
			button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 100 * 2, 150 + 180 * i));
			if ((CheckCollision(button.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
				clickSound.play();
				return i;
			}
		}
	}
	int MouseClickedWinMenu(sf::Mouse mouse) {
		for (int i = 0; i < 3; i++) {
			winButton.setPosition(sf::Vector2f(scrW / 2 - scrW / 6 + scrW / 6 * i - winButton.getGlobalBounds().width / 2, scrH / 2 + scrH / 5 - winButton.getGlobalBounds().height / 2));
			if ((CheckCollision(winButton.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
				clickSound.play();
				return i;
			}
		}
	}



};
