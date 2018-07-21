#include "RenderManager.h"
#include "Renderer.h"

#include <algorithm>


RenderManager::RenderManager()
{

}

RenderManager::~RenderManager()
{

}

void RenderManager::addRenderer(Renderer * renderer)
{
	m_renderers.push_back(renderer);
	std::sort(m_renderers.begin(), m_renderers.end());
}

void RenderManager::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	for (auto& renderer : m_renderers) {
		renderer->draw(target, states);
	}
}

void RenderManager::removeRenderer(Renderer* r) {
	auto it = std::find(m_renderers.begin(), m_renderers.end(), r);
	m_renderers.erase(it);
}
