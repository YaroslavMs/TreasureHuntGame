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
		load.loadFromFile("Assets/Art/454.png");
		textures.push_back(load);
		load.loadFromFile("Assets/Art/0000.png");
		textures.push_back(load);
		load.loadFromFile("Assets/Art/background.png");
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