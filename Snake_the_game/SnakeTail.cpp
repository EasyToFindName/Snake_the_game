#include "SnakeTail.h"
#include "Collider.h"
#include "PhysicsQuad.h"

#include "math.h"

SnakeTail::SnakeTail(BaseScene * mod) : GameObject(mod)
{
	//FIELDS
	m_size = sf::Vector2i(32, 32);

	//COMPONENTS
	auto render = addComponent<Renderer>();
	auto sprite = new sf::Sprite();
	sprite->setTexture(sf::Texture());
	sprite->setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
	sprite->setOrigin(m_size.x * 0.5, m_size.y * 0.5);
	sprite->setColor(sf::Color::Magenta);
	render->setSprite(*sprite);

	auto collider = addComponent<Collider>();
	collider->setForm(new PhysicsQuad(0, 0, m_size.x, m_size.y));
}

SnakeTail::~SnakeTail()
{
}

void SnakeTail::onCollision(const GameObject & gameObject)
{
}

GameObject * SnakeTail::clone()
{
	SnakeTail* tail = new SnakeTail(currentScene());
	copyComponentsTo(*tail);

	return tail;
}

void SnakeTail::setTarget(Transform* target)
{
	m_target = target;
}

void SnakeTail::move(float speedDt, float rotateDt)
{
	transform()->setPosition(sf::math::lerp(transform()->getPosition(), m_target->getPosition(), speedDt));
	transform()->setRotation(sf::math::lerpAngle(transform()->getRotation(), m_target->getRotation(), rotateDt));
}