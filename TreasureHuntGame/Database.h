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
		load.loadFromFile("Assets/Art/0000.png");                  //0
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
		load.loadFromFile("Assets/Art/border.png");                //9
		textures.push_back(load);
		load.loadFromFile("Assets/Art/heart.png");                 //10
		textures.push_back(load);
		load.loadFromFile("Assets/Art/fon1.png");                  //11
		textures.push_back(load);
		load.loadFromFile("Assets/Art/Diamond5.png");              //12
		textures.push_back(load);
		load.loadFromFile("Assets/Art/weapon_free.png");           //13
		textures.push_back(load);
		load.loadFromFile("Assets/Art/Obelisk.png");               //14
		textures.push_back(load);
		load.loadFromFile("Assets/Art/door.png");                  //15
		textures.push_back(load);
		load.loadFromFile("Assets/Art/key-blue.png");              //16
		textures.push_back(load);
		load.loadFromFile("Assets/Art/Saw.png");                   //17
		textures.push_back(load);
		load.loadFromFile("Assets/Art/FireTrap.png");              //18
		textures.push_back(load);
		load.loadFromFile("Assets/Art/LightningTrap.png");         //19
		textures.push_back(load);
		load.loadFromFile("Assets/Art/CeilingTrap.png");           //20
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
int sizeMultiplier = 3;