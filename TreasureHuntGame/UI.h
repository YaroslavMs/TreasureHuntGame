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
	sf::Sprite speedBoost, gravityBoost, shieldBoost;
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

	sf::Sound clickSound;

	//Pre-start history
	sf::Text stories[3];
	std::string storiesStrings[3], currentStory = "";
	float StoryTime = 100;
	float storySymbolFloat = 0;
	int storySymbol = 0;
	sf::Sound typeSound;

public:
	bool storyFinished = false;
	bool gamePaused = false;
	UI() {
		clickSound.setBuffer(DATABASE.soundBuffers.at(6));
		clickSound.setVolume(Volume);
		typeSound.setBuffer(DATABASE.soundBuffers.at(11));
		typeSound.setVolume(Volume);

		coinsText.setFont(DATABASE.fonts.at(0));
		coinsText.setCharacterSize(window.height / 27);
		coinsText.setFillColor(sf::Color::Yellow);
		coinsText.setOutlineColor(sf::Color::Black);
		coinsText.setOutlineThickness(window.height / 27 / 20);
		coinsText.setPosition(sf::Vector2f(window.width / 16, window.height / 21.6 + window.height / 9.8181 + window.height / 108));
		keyText.setFont(DATABASE.fonts.at(0));
		keyText.setCharacterSize(window.height / 27);
		keyText.setFillColor(sf::Color::Yellow);
		keyText.setOutlineColor(sf::Color::Black);
		keyText.setOutlineThickness(window.width / 27 / 20);
		keyText.setPosition(sf::Vector2f(window.width / 16, window.height / 21.6 + 2 * window.height / 9.8181 + window.height / 108));
		timeLeft.setFont(DATABASE.fonts.at(0));
		timeLeft.setCharacterSize(window.height / 27);
		timeLeft.setFillColor(sf::Color::Yellow);
		timeLeft.setOutlineColor(sf::Color::Black);
		timeLeft.setOutlineThickness(window.height / 27 / 20);
		heartBorder.setTexture(DATABASE.textures.at(9));
		heart.setTexture(DATABASE.textures.at(10));
		diamond.setTexture(DATABASE.textures.at(12));
		key.setTexture(DATABASE.textures.at(16));
		heart.setScale(sf::Vector2f(window.width / 480, window.width / 480));
		heartBorder.setScale(sf::Vector2f(window.width / 480, window.width / 480));
		diamond.setScale(sf::Vector2f(window.width / 320, window.width / 320));
		key.setScale(sf::Vector2f(window.width / 640, window.width / 640));
		speedBoost.setTexture(DATABASE.textures.at(25));
		speedBoost.setTextureRect(sf::IntRect(89, 64, 6, 8));
		speedBoost.setScale(sf::Vector2f(sizeMultiplier * window.width / 640, sizeMultiplier * window.width / 640));
		gravityBoost.setTexture(DATABASE.textures.at(25));
		gravityBoost.setTextureRect(sf::IntRect(73, 64, 7, 8));
		gravityBoost.setScale(sf::Vector2f(sizeMultiplier * window.width / 640, sizeMultiplier * window.width / 640));
		shieldBoost.setTexture(DATABASE.textures.at(27));
		shieldBoost.setScale(sf::Vector2f(sizeMultiplier * window.width / 1920, sizeMultiplier * window.width / 1920));


		background.setTexture(DATABASE.textures.at(0));
		background.setTextureRect(sf::IntRect(1160, 81, 1294 - 1160, 190 - 81));
		background.setScale(sf::Vector2f(window.width / background.getGlobalBounds().width, window.height / background.getGlobalBounds().height));
		button.setTexture(DATABASE.textures.at(2));
		button.setTextureRect(sf::IntRect(0, 0, 200, 60));
		button.setScale(window.width / 960, window.height / 720);

		text[0].setString("Pause");
		text[0].setFillColor(sf::Color::Red);
		text[0].setOutlineColor(sf::Color::White);
		text[0].setOutlineThickness(window.height / 5.4 / 40);
		text[0].setCharacterSize(window.height / 5.4);
		text[0].setFont(DATABASE.fonts.at(0));
		text[0].setOrigin(text[0].getGlobalBounds().width / 2, text[0].getGlobalBounds().height / 2);
		text[0].setPosition(sf::Vector2f(window.width / 2, window.height / 5.4));
		text[1].setString("Continue");
		text[2].setString("Restart");
		text[3].setString("Main menu");
		for (int i = 1; i < 4; i++) {
			text[i].setFont(DATABASE.fonts.at(0));
			text[i].setFillColor(sf::Color::Red);
			text[i].setCharacterSize(window.height / 13.5);
			text[i].setOutlineColor(sf::Color::White);
			text[i].setOutlineThickness(window.height / 13.5 / 40);
			text[i].setOrigin(text[i].getGlobalBounds().width / 2, text[i].getGlobalBounds().height / 2);
		}
		for (int i = 2; i <= 4; i++)
			text[i - 1].setPosition(sf::Vector2f(window.width / 2, window.height / 6.1714 + window.height / 6 * i));

		YouDied[0].setString("You Died");
		YouDied[0].setFillColor(sf::Color::Red);
		YouDied[0].setOutlineColor(sf::Color::Black);
		YouDied[0].setOutlineThickness(window.height / 3.85714 / 28);
		YouDied[0].setCharacterSize(window.height / 3.85714);
		YouDied[0].setFont(DATABASE.fonts.at(0));
		YouDied[0].setOrigin(YouDied[0].getGlobalBounds().width / 2, YouDied[0].getGlobalBounds().height / 2);
		YouDied[0].setPosition(sf::Vector2f(window.width / 2, window.height / 2 - window.height / 10.8));

		YouDied[1].setString("Respawn");
		YouDied[1].setFillColor(sf::Color::Black);
		YouDied[1].setOutlineColor(sf::Color::Red);
		YouDied[1].setOutlineThickness(window.height / 13.5 / 40);
		YouDied[1].setCharacterSize(window.height / 13.5);
		YouDied[1].setFont(DATABASE.fonts.at(0));
		YouDied[1].setOrigin(YouDied[1].getGlobalBounds().width / 2, YouDied[1].getGlobalBounds().height / 2);
		YouDied[1].setPosition(sf::Vector2f(window.width / 2, window.height / 2 + window.height / 4.8));
		Panel.setTexture(DATABASE.textures.at(2));
		Panel.setPosition(0, 0);
		Panel.setScale(sf::Vector2f(window.width / Panel.getGlobalBounds().width, window.height / Panel.getGlobalBounds().height));
		Panel.setColor(sf::Color(225, 0, 0, 60));


		winPanel.setTexture(DATABASE.textures.at(2));
		winPanel.setPosition(window.width / 4, window.height / 4);
		winPanel.setScale(sf::Vector2f(window.width / winPanel.getGlobalBounds().width / 2, window.height / winPanel.getGlobalBounds().height / 2));
		winPanel.setColor(sf::Color(60, 30, 0));
		youWinText.setString("Level Completed");
		youWinText.setFillColor(sf::Color::Red);
		youWinText.setOutlineColor(sf::Color::White);
		youWinText.setOutlineThickness(window.height / 9 / 60);
		youWinText.setCharacterSize(window.height / 9);
		youWinText.setFont(DATABASE.fonts.at(0));
		youWinText.setOrigin(youWinText.getGlobalBounds().width / 2, youWinText.getGlobalBounds().height / 2);
		youWinText.setPosition(sf::Vector2f(window.width / 2, window.height / 4 + window.height / 43.2));
		Star.setTexture(DATABASE.textures.at(21));
		Star.setTextureRect(sf::IntRect(6, 6, 20, 22));
		Star.setOrigin(Star.getGlobalBounds().width / 2, Star.getGlobalBounds().height / 2);
		Star.setScale(sf::Vector2f(window.width / 384, window.width / 384));
		winButtonsT[0].setString("To Main menu");
		winButtonsT[1].setString("Restart");
		winButtonsT[2].setString("Next level");
		for (int i = 0; i < 3; i++) {
			winButtonsT[i].setFont(DATABASE.fonts.at(0));
			winButtonsT[i].setFillColor(sf::Color::Red);
			winButtonsT[i].setCharacterSize(window.height / 21.6);
			winButtonsT[i].setOutlineColor(sf::Color::White);
			winButtonsT[i].setOutlineThickness(window.height / 13.5 / 25);
			winButtonsT[i].setOrigin(winButtonsT[i].getGlobalBounds().width / 2, winButtonsT[i].getGlobalBounds().height / 2);
		}
		winButton.setTexture(DATABASE.textures.at(2));
		winButton.setColor(sf::Color(160, 80, 0));
		winButton.setTextureRect(sf::IntRect(0, 0, 200, 60));
		winButton.setScale(window.width / 1280, window.width / 1280);


		storiesStrings[0] = "You entered ruins of an old castle,\nseeking for treasures,\nwanting to uncover mysteries of this castle.\nBut will you survive?";
		storiesStrings[1] = "Castle appeared to be much more\ndangerous than you expected.\nBut you decided not to give up\nand continue your journey";
		storiesStrings[2] = "Slowly you are getting used\nto this castle,\nBut nevertheless,\nbe careful as even\nsmall mistake\ncan lead to your death...";
		stories[0].setString(storiesStrings[0]);
		stories[1].setString(storiesStrings[1]);
		stories[2].setString(storiesStrings[2]);
		for (int i = 0; i < 3; i++) {

			stories[i].setFillColor(sf::Color::Red);
			stories[i].setOutlineColor(sf::Color::White);
			stories[i].setOutlineThickness(window.height / 10 / 40);
			stories[i].setCharacterSize(window.height / 10);
			stories[i].setFont(DATABASE.fonts.at(0));
			stories[i].setOrigin(stories[i].getGlobalBounds().width / 2, stories[i].getGlobalBounds().height / 2);
			stories[i].setPosition(sf::Vector2f(window.width / 2, window.height / 2));
		}
		stories[0].setString("");
		stories[1].setString("");
		stories[2].setString("");

	}
	void UpdateVolume() {
		clickSound.setVolume(Volume);
		typeSound.setVolume(Volume);
	}

	void Update(float time) {
		currentFrame += time * 0.003;
		currentKey += time * 0.003;
		if (StoryTime >= 0) {
			StoryTime -= (time * 400 / 1000000.0f);
			storySymbolFloat += time * 0.01;
		}
	}
	void Draw(Player player) {
		//WinMenu(3);

		amountOfCoins = player.coinsCollected <= 0 ? "" : std::to_string(player.coinsCollected);
		keyString = std::to_string(player.keysFound) + " / " + std::to_string(3) + " keys found.";
		coinsText.setString(amountOfCoins);
		keyText.setString(keyString);
		for (int i = 0; i < player.lives; i++)
		{
			heart.setPosition(window.width / 38.4 + i * window.width / 24, window.height / 21.6);
			window.Renderer.draw(heart);
		}
		for (int i = 0; i < 5; i++)
		{
			heartBorder.setPosition(window.width / 38.4 + i * window.width / 24, window.height / 21.6);
			window.Renderer.draw(heartBorder);
		}
		if (currentFrame >= 5)
			currentFrame = 0;
		diamond.setTextureRect(sf::IntRect(0 + 8 * (int)currentFrame, 0, 8, 9));
		diamond.setPosition(window.width / 38.4, window.height / 21.6 + window.height / 9.8181);
		if (currentKey >= 12)
			currentKey = 0;
		key.setTextureRect(sf::IntRect(10 + (int)currentKey * 32, 0, 12, 32));
		key.setPosition(window.width / 38.4, window.height / 21.6 + 2 * window.height / 9.8181);
		if (player.speedBoostTime > 0) {
			speedBoost.setPosition(window.width / 38.4, window.height / 21.6 + 3 * window.height / 9.8181);
			timeString = std::to_string(player.speedBoostTime).substr(0, 3);
			timeLeft.setString(timeString);
			timeLeft.setPosition(sf::Vector2f(window.width / 16, window.height / 21.6 + 3 * window.height / 9.8181 + window.height / 108));
			window.Renderer.draw(speedBoost);
			window.Renderer.draw(timeLeft);
		}
		if (player.gravityBoostTime > 0) {
			gravityBoost.setPosition(window.width / 38.4, window.height / 21.6 + 4 * window.height / 9.8181);
			timeString = std::to_string(player.gravityBoostTime).substr(0, 3);
			timeLeft.setString(timeString);
			timeLeft.setPosition(sf::Vector2f(window.width / 16, window.height / 21.6 + 4 * window.height / 9.8181 + window.height / 108));
			window.Renderer.draw(gravityBoost);
			window.Renderer.draw(timeLeft);
		}
		if (player.shieldTime > 0) {
			shieldBoost.setPosition(window.width / 38.4, window.height / 21.6 + 5 * window.height / 9.8181);
			timeString = std::to_string(player.shieldTime).substr(0, 3);
			timeLeft.setString(timeString);
			timeLeft.setPosition(sf::Vector2f(window.width / 16, window.height / 21.6 + 5 * window.height / 9.8181 + window.height / 108));
			window.Renderer.draw(shieldBoost);
			window.Renderer.draw(timeLeft);
		}
		window.Renderer.draw(key);
		window.Renderer.draw(coinsText);
		window.Renderer.draw(keyText);
		window.Renderer.draw(diamond);
		if (gamePaused) {
			PauseMenu();
		}
		if (StoryTime > 0)
			StoryMenu(player);
		else storyFinished = true;
	}

	void PauseMenu() {
		window.Renderer.draw(background);
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		for (int i = 2; i <= 4; i++) {

			button.setPosition(sf::Vector2f(window.width / 2 - window.width / 9.6, window.height / 7.2 + window.height / 6 * i));
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
			Star.setPosition(sf::Vector2f(window.width / 2 - window.width / 16 + window.width / 16 * i, window.height / 6 * 3));
			if (i >= stars)
				Star.setColor(sf::Color(0, 0, 0, 70));
			else Star.setColor(sf::Color::White);
			window.Renderer.draw(Star);
		}
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		for (int i = 0; i < 3; i++) {
			winButton.setPosition(sf::Vector2f(window.width / 2 - window.width / 6 + window.width / 6 * i - winButton.getGlobalBounds().width / 2, window.height / 2 + window.height / 5 - winButton.getGlobalBounds().height / 2));
			winButtonsT[i].setPosition(sf::Vector2f(window.width / 2 - window.width / 6 + window.width / 6 * i, window.height / 2 + window.height / 5));
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
		button.setPosition(sf::Vector2f(window.width / 2 - button.getGlobalBounds().width / 2, window.height / 2 + window.height / 5.4));
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
		button.setPosition(sf::Vector2f(window.width / 2 - button.getGlobalBounds().width / 2, window.height / 2 + window.height / 5.4));
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
			button.setPosition(sf::Vector2f(window.width / 2 - window.width / 9.6, window.height / 7.2 + window.height / 6 * i));
			if ((CheckCollision(button.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
				clickSound.play();
				return i;
			}
		}
	}
	int MouseClickedWinMenu(sf::Mouse mouse) {
		for (int i = 0; i < 3; i++) {
			winButton.setPosition(sf::Vector2f(window.width / 2 - window.width / 6 + window.width / 6 * i - winButton.getGlobalBounds().width / 2, window.height / 2 + window.height / 5 - winButton.getGlobalBounds().height / 2));
			if ((CheckCollision(winButton.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
				clickSound.play();
				return i;
			}
		}
	}

	void StoryMenu(Player player) {


		window.Renderer.draw(background);
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		if (storySymbol < storiesStrings[player.scene->levelNumber].length() && storySymbolFloat > storySymbol) {
			currentStory += storiesStrings[player.scene->levelNumber][storySymbol];
			storySymbol++;
			if (typeSound.getStatus() == sf::Music::Stopped)
				typeSound.play();
			if (storySymbol == storiesStrings[player.scene->levelNumber].length())
				StoryTime = 2;
		}

		stories[player.scene->levelNumber].setString(currentStory);
		window.Renderer.draw(stories[player.scene->levelNumber]);

	}


};
