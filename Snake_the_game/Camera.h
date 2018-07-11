#pragma once
#include <SFML\Graphics.hpp>
#include <memory>

class GameObject;

class Camera {

public:
	explicit Camera(sf::RenderWindow& window);
	~Camera();

	void update(float dt);

	void setPosition(const sf::Vector2f& pos);
	void setTarget(GameObject* object);


private:
	sf::RenderWindow* m_window;
	std::unique_ptr<sf::View> m_view;

	GameObject* m_target;
};