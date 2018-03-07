#pragma once
#include <SFML\Graphics.hpp>

#include <memory>

#include "Component.h"
#include "RenderCanvas.h"
#include "GameManager.h"

COMPONENT(Renderer)
public:
	Renderer(GameObject* gameObject);
	virtual ~Renderer();

	void draw(sf::RenderTarget& target, sf::RenderStates states);

private:
	std::shared_ptr<RenderCanvas> m_canvas;
	sf::Sprite* m_sprite;
END_COMPONENT