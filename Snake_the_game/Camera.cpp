#include "Camera.h"
#include "GameObject.h"

Camera::Camera(sf::RenderWindow & window) : m_window(&window)
{
	m_view = std::make_unique<sf::View>(sf::FloatRect(0.0f, 0.0f, window.getSize().x, window.getSize().y));
	m_window->setView(*m_view);
}

Camera::~Camera()
{
}

void Camera::update(float dt)
{
	if (m_target) {
		setPosition(m_target->transform()->getPosition());
	}
}

void Camera::setPosition(const sf::Vector2f & pos)
{
	m_view->setCenter(pos);
	m_window->setView(*m_view);
}

void Camera::setTarget(GameObject * object)
{
	m_target = object;
}
