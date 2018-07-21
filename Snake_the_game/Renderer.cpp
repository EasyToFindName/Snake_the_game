#include "Renderer.h"
#include "GameObject.h"

Renderer::Renderer(GameObject* gameObject) : Component(gameObject)
{
	gameObject->currentScene()->renderManager.addRenderer(this);
}

Renderer::~Renderer()
{
	/*Module* activeModule = _GameManager.topModule();

	if (activeModule) {
		activeModule->renderManager.removeRenderer(this);
	}*/
	m_gameObject->currentScene()->renderManager.removeRenderer(this);
}

void Renderer::draw(sf::RenderTarget & target, sf::RenderStates states)
{
	states.transform *= m_gameObject->transform()->getTransform();
	target.draw(*m_sprite, states);
}

bool Renderer::operator<(const Renderer& renderer)
{
	return this->m_layer < renderer.m_layer;
}

Component * Renderer::clone(GameObject * gameObject)
{
	Renderer* component = new Renderer(gameObject);

	component->m_sprite = new sf::Sprite(*m_sprite);
	component->m_layer = m_layer;

	return component;
}

void Renderer::setSprite(sf::Sprite &sprite)
{
	m_sprite = &sprite;
}
