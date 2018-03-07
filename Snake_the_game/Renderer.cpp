#include "Renderer.h"
#include "GameObject.h"

Renderer::Renderer(GameObject * gameObject) : Component(gameObject)
{
	m_canvas = std::make_shared<RenderCanvas>();
	m_canvas->setDrawCallback(std::bind(&Renderer::draw, this, std::placeholders::_1, std::placeholders::_2));
	GameManager::getInstance().renderManager()->addCanvas(m_canvas);

	m_sprite = new sf::Sprite();
	m_sprite->setTexture(sf::Texture());
	m_sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_sprite->setColor(sf::Color::Red);
}

Renderer::~Renderer()
{
}

void Renderer::draw(sf::RenderTarget & target, sf::RenderStates states)
{
	states.transform *= m_gameObject->transform()->getTransform();
	target.draw(*m_sprite, states);
}

COMPONENT Renderer::getID()
{
	return COMPONENT::RENDERER;
}
