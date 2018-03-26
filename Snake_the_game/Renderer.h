#pragma once
#include <SFML\Graphics.hpp>

#include <memory>

#include "Component.h"
#include "GameManager.h"

using RenderLayer = unsigned;

COMPONENT(Renderer)
public:
	Renderer(GameObject* gameObject);
	virtual ~Renderer();

	bool operator<(const Renderer& renderer);

	virtual Component* clone(GameObject* gameObject) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states);
	
private:
	sf::Sprite* m_sprite;
	RenderLayer m_layer = 0;

END_COMPONENT(Renderer)