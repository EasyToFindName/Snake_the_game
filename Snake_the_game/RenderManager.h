#pragma once
#include <vector>
#include <memory>
#include <algorithm>

#include <SFML\Graphics.hpp>

//#include "RenderCanvas.h"
class Renderer;

class RenderManager {
public:
	RenderManager();
	~RenderManager();

	RenderManager(const RenderManager&) = delete;
	void operator=(const RenderManager&) = delete;

	
	void addRenderer(Renderer* renderer);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void removeRenderer(Renderer* r);
private:

	std::vector<Renderer*> m_renderers;
};