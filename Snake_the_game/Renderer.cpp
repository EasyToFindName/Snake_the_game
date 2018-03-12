#include "Renderer.h"
#include "GameObject.h"
Renderer::Renderer(GameObject* gameObject) : Component(gameObject)
{

	GameManager::getInstance().renderManager()->addRenderer(this);

	m_sprite = new sf::Sprite();
	m_sprite->setTexture(sf::Texture());
	m_sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_sprite->setColor(sf::Color::Red);
}

Renderer::~Renderer()
{
	GameManager::getInstance().renderManager()->removeRenderer(this);
}

void Renderer::draw(sf::RenderTarget & target, sf::RenderStates states)
{
	states.transform *= m_gameObject->transform().getTransform();
	target.draw(*m_sprite, states);
}

bool Renderer::operator<(const Renderer& renderer)
{
	return this->m_layer < renderer.m_layer;
}
