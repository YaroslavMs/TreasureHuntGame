#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Database.h"

enum class ActiveMenu
{
	MainMenu,
	OptionsMenu,
	LevelsMenu,

};

class MainMenu {

	sf::Sprite background, button;
	sf::Text text[3], name;
	sf::Sound clickSound;
	sf::Sound music;

	//OptionsMenu
	sf::Text Opt;
	sf::Text options[1];
	sf::CircleShape volumeCircle;
	sf::RectangleShape volumeRect, volumeAmount;
	sf::FloatRect changeVolumeCol;
	sf::Text LeaveOptMenu;


	//Levels menu
	sf::Text LevelsT;
	sf::Sprite levelButton, Lock, Star;
	sf::Text levelNumb;
	int amountOfLevels = 2;

public:
	ActiveMenu currentMenu = ActiveMenu::MainMenu;
	MainMenu() {
		clickSound.setBuffer(DATABASE.soundBuffers.at(6));
		clickSound.setVolume(Volume);
		music.setBuffer(DATABASE.soundBuffers.at(7));
		music.setVolume(Volume);

		//Main menu
		background.setTexture(DATABASE.textures.at(0));
		background.setTextureRect(sf::IntRect(1160, 81, 1294 - 1160, 190 - 81));
		background.setScale(sf::Vector2f(sf::VideoMode::getDesktopMode().width / background.getGlobalBounds().width, sf::VideoMode::getDesktopMode().height / background.getGlobalBounds().height));
		button.setTexture(DATABASE.textures.at(2));
		button.setTextureRect(sf::IntRect(0, 0, 200, 60));
		button.setScale(2, 1.5);
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

		//Option menu
		Opt.setString("Options");
		Opt.setFillColor(sf::Color::Red);
		Opt.setOutlineColor(sf::Color::White);
		Opt.setOutlineThickness(5);
		Opt.setCharacterSize(200);
		Opt.setFont(DATABASE.fonts.at(0));
		Opt.setOrigin(Opt.getGlobalBounds().width / 2, Opt.getGlobalBounds().height / 2);
		Opt.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 70));

		options[0].setString("Volume: ");
		for (int i = 0; i < 1; i++) {
			options[i].setFont(DATABASE.fonts.at(0));
			options[i].setFillColor(sf::Color::Red);
			options[i].setCharacterSize(80);
			options[i].setOutlineColor(sf::Color::White);
			options[i].setOutlineThickness(2);
			options[i].setOrigin(options[i].getGlobalBounds().width / 2, options[i].getGlobalBounds().height / 2);
		}
		for (int i = 1; i <= 1; i++)
			options[i - 1].setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 8, 100 + 180 * i));

		volumeRect.setSize(sf::Vector2f(100 * 4, 3 * 4));
		volumeRect.setFillColor(sf::Color::Black);
		volumeRect.setOrigin(sf::Vector2f(0, volumeRect.getSize().y / 2));
		volumeRect.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 8 + 200, 310));
		changeVolumeCol.left = sf::VideoMode::getDesktopMode().width / 8 + 200;
		changeVolumeCol.top = 310 - volumeRect.getSize().y * 2;
		changeVolumeCol.width = volumeRect.getSize().x;
		changeVolumeCol.height = volumeRect.getSize().y * 4;

		volumeAmount.setSize(sf::Vector2f(Volume * 4, 3 * 4));
		volumeAmount.setFillColor(sf::Color::Red);
		volumeAmount.setOrigin(sf::Vector2f(0, volumeRect.getSize().y / 2));
		volumeAmount.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 8 + 200, 310));

		volumeCircle.setRadius(10);
		volumeCircle.setOrigin(sf::Vector2f(10, 10));
		volumeCircle.setFillColor(sf::Color::White);
		volumeCircle.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 8 + 200 + Volume * 4, 310));

		LeaveOptMenu.setString("Main menu");
		LeaveOptMenu.setFont(DATABASE.fonts.at(0));
		LeaveOptMenu.setFillColor(sf::Color::Red);
		LeaveOptMenu.setCharacterSize(80);
		LeaveOptMenu.setOutlineColor(sf::Color::White);
		LeaveOptMenu.setOutlineThickness(2);
		LeaveOptMenu.setOrigin(LeaveOptMenu.getGlobalBounds().width / 2, LeaveOptMenu.getGlobalBounds().height / 2);
		LeaveOptMenu.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height - 100));



		//Levels menu
		LevelsT.setString("Levels");
		LevelsT.setFillColor(sf::Color::Red);
		LevelsT.setOutlineColor(sf::Color::White);
		LevelsT.setOutlineThickness(5);
		LevelsT.setCharacterSize(200);
		LevelsT.setFont(DATABASE.fonts.at(0));
		LevelsT.setOrigin(LevelsT.getGlobalBounds().width / 2, LevelsT.getGlobalBounds().height / 2);
		LevelsT.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 70));

		levelButton.setTexture(DATABASE.textures.at(23));
		levelButton.setTextureRect(sf::IntRect(4, 4, 59, 59));
		levelButton.setOrigin(sf::Vector2f(27.5, 27.5));
		levelButton.setScale(4, 4);
		levelButton.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2));
		levelButton.setColor(sf::Color(70, 0, 0, 255));

		Lock.setTexture(DATABASE.textures.at(24));
		Lock.setOrigin(sf::Vector2f(7.5, 7.5));
		Lock.setScale(11, 11);
		Lock.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2));
		//	levelButton.setColor(sf::Color(100, 255, 255, 255));

		levelNumb.setString("1");
		levelNumb.setStyle(sf::Text::Bold);
		levelNumb.setFont(DATABASE.fonts.at(0));
		levelNumb.setFillColor(sf::Color::Red);
		levelNumb.setCharacterSize(140);
		levelNumb.setOrigin(levelNumb.getGlobalBounds().width / 2, levelNumb.getGlobalBounds().height);

		Star.setTexture(DATABASE.textures.at(21));
		Star.setTextureRect(sf::IntRect(6, 6, 20, 22));
		Star.setOrigin(Star.getGlobalBounds().width / 2, Star.getGlobalBounds().height / 2);
		Star.setScale(sf::Vector2f(2, 2));
	}
	int UpdateMenu(Level levels[2]) {

		if (music.getStatus() == sf::Sound::Stopped || music.getStatus() == sf::Sound::Paused) {
			music.play();
		}
		window.Renderer.draw(background);
		if (currentMenu == ActiveMenu::MainMenu) {
			DrawMainMenu();
		}
		else if (currentMenu == ActiveMenu::OptionsMenu)
			OptionsMenu();
		else if (currentMenu == ActiveMenu::LevelsMenu)
			LevelsMenu(levels);
		return 0;
	}
	void DrawMainMenu() {

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

	}
	void OptionsMenu() {
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		window.Renderer.draw(Opt);
		window.Renderer.draw(options[0]);
		window.Renderer.draw(volumeRect);
		window.Renderer.draw(volumeAmount);
		window.Renderer.draw(volumeCircle);

		button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 200, sf::VideoMode::getDesktopMode().height - 120));
		if (CheckCollision(button.getGlobalBounds(), mousePos)) {
			button.setColor(sf::Color(100, 0, 0, 255));
		}
		else button.setColor(sf::Color::White);
		window.Renderer.draw(button);
		window.Renderer.draw(LeaveOptMenu);

	}
	void ChangeVolume() {
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		if (CheckCollision(changeVolumeCol, mousePos)) {
			volumeCircle.setPosition(sf::Vector2f(mousePos.x, 310));
			Volume = (mousePos.x - (sf::VideoMode::getDesktopMode().width / 8 + 200)) / 4;
			volumeAmount.setSize(sf::Vector2f(Volume * 4, 3 * 4));

		}
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

	int MouseClicked(sf::Mouse mouse, Level levels[2]) {
		if (currentMenu == ActiveMenu::MainMenu) {
			for (int i = 1; i <= 3; i++) {
				button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 100 * 2, 250 + 180 * i));
				if ((CheckCollision(button.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
					clickSound.play();
					music.pause();
					if (i == 1)
						currentMenu = ActiveMenu::LevelsMenu;
					else if (i == 2)
						currentMenu = ActiveMenu::OptionsMenu;
					else window.Renderer.close();
				}
			}
		}
		else {
			button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 200, sf::VideoMode::getDesktopMode().height - 120));
			if ((CheckCollision(button.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
				clickSound.play();
				currentMenu = ActiveMenu::MainMenu;
			}
			else if (currentMenu == ActiveMenu::LevelsMenu) {
				for (int i = 0; i < amountOfLevels; i++) {
					levelButton.setPosition(sf::Vector2f(200 + 300 * i, sf::VideoMode::getDesktopMode().height / 2));
					if (i == 0 || levels[i - 1].bestScore > 0) {
						if (CheckCollision(levelButton.getGlobalBounds(), mouse.getPosition(window.Renderer))) {
							clickSound.play();
							music.pause();
							return i;
						}

					}
				}
			}
		}

		return -1;
	}
	void UpdateVolume() {
		clickSound.setVolume(Volume);
		music.setVolume(Volume);
	}

	void LevelsMenu(Level levels[2]) {
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		window.Renderer.draw(LevelsT);
		for (int i = 0; i < amountOfLevels; i++) {
			levelNumb.setPosition(sf::Vector2f(200 + 300 * i, sf::VideoMode::getDesktopMode().height / 2));
			levelNumb.setString(std::to_string(i + 1));
			levelNumb.setOrigin(levelNumb.getGlobalBounds().width / 2, levelNumb.getGlobalBounds().height);
			levelButton.setPosition(sf::Vector2f(200 + 300 * i, sf::VideoMode::getDesktopMode().height / 2));
			Lock.setPosition(sf::Vector2f(200 + 300 * i, sf::VideoMode::getDesktopMode().height / 2));
			levelButton.setColor(sf::Color(70, 0, 0, 255));
			if (i == 0 || levels[i - 1].bestScore > 0) {

				if (CheckCollision(levelButton.getGlobalBounds(), mousePos)) {
					levelButton.setColor(sf::Color(50, 0, 0, 255));
				}

			}
			window.Renderer.draw(levelButton);
			window.Renderer.draw(levelNumb);
			if (i != 0 && levels[i - 1].bestScore == 0)
				window.Renderer.draw(Lock);
			if (i == 0 || levels[i - 1].bestScore > 0)
				for (int j = 0; j < 3; j++) {
					Star.setPosition(sf::Vector2f(200 + 300 * i - levelButton.getLocalBounds().width+ levelButton.getLocalBounds().width * j, sf::VideoMode::getDesktopMode().height / 2 + levelButton.getLocalBounds().height * 1.3));
					if (j >= levels[i].bestScore)
						Star.setColor(sf::Color(0, 0, 0, 70));
					else Star.setColor(sf::Color::White);
					window.Renderer.draw(Star);
				}
		}
		button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 200, sf::VideoMode::getDesktopMode().height - 120));
		if (CheckCollision(button.getGlobalBounds(), mousePos)) {
			button.setColor(sf::Color(100, 0, 0, 255));
		}
		else button.setColor(sf::Color::White);
		window.Renderer.draw(button);
		window.Renderer.draw(LeaveOptMenu);

	}
};