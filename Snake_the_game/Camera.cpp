#include "Camera.h"
#include "GameObject.h"

//#include <iostream>

Camera::Camera(sf::RenderWindow & window, BaseScene& scene) : m_window(&window), m_scene(&scene)
{
	m_view = std::make_unique<sf::View>(sf::FloatRect(0.0f, 0.0f, window.getSize().x, window.getSize().y));
	m_view->setViewport(sf::FloatRect(0, 0, 1, 1));

	m_window->setView(*m_view);
}

Camera::~Camera()
{
}

void Camera::update(float dt)
{
	if (m_target) {
		setCenterPosition(m_target->transform()->getPosition());
	}
}

void Camera::setCenterPosition(const sf::Vector2f & pos)
{
	m_view->setCenter(checkPosition(pos));
	m_window->setView(*m_view);
}

void Camera::setTarget(GameObject * object)
{
	m_target = object;
}

sf::Vector2f Camera::checkPosition(sf::Vector2f newCenterPos)
{
	auto camPos = newCenterPos - (m_view->getSize() * 0.5f);
	auto camSize = m_view->getSize();
	auto sceneSize = m_scene->sceneSize();

	if (camPos.x < 0.0f)
	{
		newCenterPos.x = camSize.x * 0.5f;
	}
	if (camPos.y < 0.0f)
	{
		newCenterPos.y = camSize.y * 0.5f;
	}

	if (camPos.x + camSize.x > sceneSize.x)
	{
		newCenterPos.x = sceneSize.x - camSize.x * 0.5f;
	}

	if (camPos.y + camSize.y > sceneSize.y)
	{
		newCenterPos.y = sceneSize.y - camSize.y * 0.5f;
	}
	return newCenterPos;
}
