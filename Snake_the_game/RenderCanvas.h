#pragma once

#include <functional>
#include <SFML\Graphics.hpp>

using RenderLayer = unsigned;

class RenderCanvas {
public:
	RenderCanvas();
	~RenderCanvas();

	RenderCanvas(const RenderCanvas& canvas);
	RenderCanvas& operator=(const RenderCanvas& canvas);
	
	bool operator < (const RenderCanvas& canvas);

	void setDrawCallback(std::function<void(sf::RenderTarget&, sf::RenderStates states)> function);

	void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
	RenderLayer m_layer = 0;
	std::function<void(sf::RenderTarget&, sf::RenderStates states)> m_drawCallback;
};