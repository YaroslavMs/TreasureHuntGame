#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class TexturesDatabase {

	
public:
	std::vector<sf::Texture> textures;
	void AddTextureToDatabase(sf::Texture texture) {
		textures.push_back(texture);
	}
	sf::Texture GetTextureById(int id) {
		return textures.at(id);
	}
};