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

	/*void addCanvas(const std::shared_ptr<RenderCanvas>& canvas);
	void removeCanvas(const std::shared_ptr<RenderCanvas>& canvas);*/

	void addRenderer(Renderer* renderer);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	//std::vector<std::shared_ptr<RenderCanvas>> m_canvases;

	std::vector<Renderer*> m_renderers;
};