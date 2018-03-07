#include "RenderManager.h"

RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{

}

void RenderManager::addCanvas(const std::shared_ptr<RenderCanvas>& canvas)
{
	m_canvases.push_back(canvas);
	std::sort(m_canvases.begin(), m_canvases.end());
}

void RenderManager::removeCanvas(const std::shared_ptr<RenderCanvas>& canvas)
{
	for (auto it = m_canvases.cbegin(); it != m_canvases.cend(); it++) {
		if (it->get() == canvas.get()) {
			m_canvases.erase(it);
			return;
		}

	}
}

void RenderManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto& canvas : m_canvases) {
		canvas->draw(target, states);
	}
}
