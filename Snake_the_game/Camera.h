#pragma once
#include <SFML\Graphics.hpp>
#include <memory>

class GameObject;
class BaseScene;

class Camera {

public:
	explicit Camera(sf::RenderWindow& window, BaseScene& scene);
	~Camera();

	void update(float dt);

	void setCenterPosition(const sf::Vector2f& pos);
	void setTarget(GameObject* object);

private:
	sf::Vector2f checkPosition(sf::Vector2f newCenterPos);


private:
	sf::RenderWindow* m_window;
	BaseScene* m_scene;
	std::unique_ptr<sf::View> m_view;

	GameObject* m_target;
};