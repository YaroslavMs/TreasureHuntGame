#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class Database {


public:
	std::vector<sf::Texture> textures;
	std::vector<sf::Font> fonts;
	Database() {
		sf::Texture load;
		load.loadFromFile("Assets/Art/0000.png");                   //0
		textures.push_back(load);                                     
		load.loadFromFile("Assets/Art/0000.png");                  //1
		textures.push_back(load);
		load.loadFromFile("Assets/Art/background.png");            //2
		textures.push_back(load);
		load.loadFromFile("Assets/Art/_Idle.png");                 //3
		textures.push_back(load);
		load.loadFromFile("Assets/Art/_Run.png");                  //4
		textures.push_back(load);
		load.loadFromFile("Assets/Art/_Jump.png");                 //5
		textures.push_back(load);
		load.loadFromFile("Assets/Art/_Fall.png");                 //6                
		textures.push_back(load);
		load.loadFromFile("Assets/Art/_Crouch.png");               //7
		textures.push_back(load);
		load.loadFromFile("Assets/Art/_CrouchWalk.png");           //8
		textures.push_back(load);
		sf::Font loadFont;
		loadFont.loadFromFile("Assets/Fonts/CaslonAntique.ttf");
		fonts.push_back(loadFont);

	}
	void AddTextureToDatabase(sf::Texture texture) {
		textures.push_back(texture);
	}
};

Database DATABASE;