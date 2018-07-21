#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <memory>
#include <unordered_map>
#include <string>

class ResourceCacher {
public:
	sf::Font* getFont(const std::string& filePath);
	sf::Texture* getTexture(const std::string& filePath);
protected:
	sf::Font* loadFont(const std::string& filePath);
	sf::Texture* loadTexture(const std::string& filePath);
private:
	std::unordered_map<std::string, std::unique_ptr<sf::Font>> m_fonts;
	std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
};