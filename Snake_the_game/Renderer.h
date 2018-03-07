#pragma once
#include <SFML\Graphics.hpp>

#include <memory>

#include "Component.h"
#include "RenderCanvas.h"
#include "GameManager.h"

class Renderer : public Component {
public:
	Renderer(GameObject* gameObject);
	virtual ~Renderer();

	void draw(sf::RenderTarget& target, sf::RenderStates states);

	static COMPONENT getID();
private:
	std::shared_ptr<RenderCanvas> m_canvas;
	sf::Sprite* m_sprite;
};