#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Database.h"
#include "KeyButtons.h"

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
	sf::Text Opt, ButtonsText[3][5];
	sf::Text volumeText;
	sf::CircleShape volumeCircle;
	sf::RectangleShape volumeRect, volumeAmount;
	sf::RectangleShape Fields[2][4];
	sf::FloatRect changeVolumeCol;
	sf::Text LeaveOptMenu, resetSet;
	int iChangeable = -1, jChangable = -1;
	bool Picked = false;


	//Levels menu
	sf::Text LevelsT;
	sf::Sprite levelButton, Lock, Star;
	sf::Text levelNumb;
	const int amountOfLevels = 3;

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
		Opt.setCharacterSize(120);
		Opt.setFont(DATABASE.fonts.at(0));
		Opt.setOrigin(Opt.getGlobalBounds().width / 2, Opt.getGlobalBounds().height);
		Opt.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, 120));

		volumeText.setString("Volume: ");
		volumeText.setFont(DATABASE.fonts.at(0));
		volumeText.setFillColor(sf::Color::Red);
		volumeText.setCharacterSize(60);
		volumeText.setOutlineColor(sf::Color::White);
		volumeText.setOutlineThickness(2);
		volumeText.setOrigin(0, volumeText.getGlobalBounds().height);
		volumeText.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width, 100 + 180));

		volumeRect.setSize(sf::Vector2f(100 * 4, 3 * 4));
		volumeRect.setFillColor(sf::Color::Black);
		volumeRect.setOrigin(sf::Vector2f(0, volumeRect.getSize().y / 2));
		volumeRect.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width + 200, 280));
		changeVolumeCol.left = sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width + 200;
		changeVolumeCol.top = 280 - volumeRect.getSize().y * 2;
		changeVolumeCol.width = volumeRect.getSize().x;
		changeVolumeCol.height = volumeRect.getSize().y * 4;

		volumeAmount.setSize(sf::Vector2f(Volume * 4, 3 * 4));
		volumeAmount.setFillColor(sf::Color::Red);
		volumeAmount.setOrigin(sf::Vector2f(0, volumeRect.getSize().y / 2));
		volumeAmount.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width + 200, 280));

		volumeCircle.setRadius(10);
		volumeCircle.setOrigin(sf::Vector2f(10, 10));
		volumeCircle.setFillColor(sf::Color::White);
		volumeCircle.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width + 200 + Volume * 4, 280));

		LeaveOptMenu.setString("Main menu");
		LeaveOptMenu.setFont(DATABASE.fonts.at(0));
		LeaveOptMenu.setFillColor(sf::Color::Red);
		LeaveOptMenu.setCharacterSize(80);
		LeaveOptMenu.setOutlineColor(sf::Color::White);
		LeaveOptMenu.setOutlineThickness(2);
		LeaveOptMenu.setOrigin(LeaveOptMenu.getGlobalBounds().width / 2, LeaveOptMenu.getGlobalBounds().height / 2);
		LeaveOptMenu.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height - 100));

		resetSet.setString("Reset Settings");
		resetSet.setFont(DATABASE.fonts.at(0));
		resetSet.setFillColor(sf::Color::Red);
		resetSet.setCharacterSize(80);
		resetSet.setOutlineColor(sf::Color::White);
		resetSet.setOutlineThickness(2);
		resetSet.setOrigin(resetSet.getGlobalBounds().width / 2, resetSet.getGlobalBounds().height / 2);
		resetSet.setPosition(sf::Vector2f(300, sf::VideoMode::getDesktopMode().height - 100));

		ButtonsText[0][0].setString("Action");
		ButtonsText[1][0].setString("Primary");
		ButtonsText[2][0].setString("Secondary");
		ButtonsText[0][1].setString("Jump");
		ButtonsText[0][2].setString("Left");
		ButtonsText[0][3].setString("Right");
		ButtonsText[0][4].setString("Crouch");
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {

				ButtonsText[i][j].setFillColor(sf::Color::Red);
				ButtonsText[i][j].setOutlineColor(sf::Color::White);
				ButtonsText[i][j].setOutlineThickness(3);
				ButtonsText[i][j].setCharacterSize(60);
				ButtonsText[i][j].setFont(DATABASE.fonts.at(0));
				ButtonsText[i][j].setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - ButtonsText[1][0].getGlobalBounds().width / 2 - 500 + i * 500, 380 + 100 * j));
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				Fields[i][j].setSize(sf::Vector2f(260, 60));
				Fields[i][j].setFillColor(sf::Color(192, 192, 192));
				Fields[i][j].setOutlineColor(sf::Color::White);
				Fields[i][j].setOutlineThickness(3);
				Fields[i][j].setOutlineColor(sf::Color::Red);
				Fields[i][j].setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - ButtonsText[1][0].getGlobalBounds().width / 2 + i * 500 - 30, 480 + 100 * j + 10));

			}
		}

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
	int UpdateMenu(Level levels[]) {

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
		window.Renderer.draw(volumeText);
		window.Renderer.draw(volumeRect);
		window.Renderer.draw(volumeAmount);
		window.Renderer.draw(volumeCircle);

		button.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - 200, sf::VideoMode::getDesktopMode().height - 120));
		if (CheckCollision(button.getGlobalBounds(), mousePos)) {
			button.setColor(sf::Color(100, 0, 0, 255));
		}
		else button.setColor(sf::Color::White);
		window.Renderer.draw(button);
		button.setPosition(sf::Vector2f(100, sf::VideoMode::getDesktopMode().height - 120));
		if (CheckCollision(button.getGlobalBounds(), mousePos)) {
			button.setColor(sf::Color(100, 0, 0, 255));
		}
		else button.setColor(sf::Color::White);
		window.Renderer.draw(button);
		window.Renderer.draw(LeaveOptMenu);
		window.Renderer.draw(resetSet);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				window.Renderer.draw(Fields[i][j]);
				if (i == iChangeable && j == jChangable)
					ButtonsText[i + 1][j + 1].setString("|");
				else ButtonsText[i + 1][j + 1].setString(KeyNames[Controls.keys[j][i]]);
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {

				window.Renderer.draw(ButtonsText[i][j]);
			}
		}


	}
	void CheckField() {
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				if (CheckCollision(Fields[i][j].getGlobalBounds(), mousePos)) {
					if (Picked) {
						Picked = false;
						jChangable = -5;
						iChangeable = -5;
					}
					else {
						iChangeable = i;
						jChangable = j;
						Picked = true;
					}
				}


			}
		}
	}
	void ChangeButton(sf::Keyboard::Key key) {
		if (Picked) {
			Controls.keys[jChangable][iChangeable] = key;
			jChangable = -1;
			iChangeable = -1;
			Picked = false;
		}


	}
	void ChangeVolume() {
		sf::Mouse mouse;
		sf::Vector2i mousePos = mouse.getPosition(window.Renderer);
		if (CheckCollision(changeVolumeCol, mousePos)) {
			volumeCircle.setPosition(sf::Vector2f(mousePos.x, 280));
			Volume = (mousePos.x - ((sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width) + 200)) / 4;
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

	int MouseClicked(sf::Mouse mouse, Level levels[]) {
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
			else if (currentMenu == ActiveMenu::OptionsMenu) {
				button.setPosition(sf::Vector2f(100, sf::VideoMode::getDesktopMode().height - 120));
				if ((CheckCollision(button.getGlobalBounds(), mouse.getPosition(window.Renderer)))) {
					clickSound.play();
					ResetSettings();
				}

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

	void LevelsMenu(Level levels[]) {
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
					Star.setPosition(sf::Vector2f(200 + 300 * i - levelButton.getLocalBounds().width + levelButton.getLocalBounds().width * j, sf::VideoMode::getDesktopMode().height / 2 + levelButton.getLocalBounds().height * 1.3));
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
	void ResetSettings() {
		Controls = KeyButtons();
		Volume = 10;
		volumeCircle.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width / 2 - Opt.getGlobalBounds().width + 200 + Volume * 4, 280));
		volumeAmount.setSize(sf::Vector2f(Volume * 4, 3 * 4));
	}
};