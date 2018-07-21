#include "Saw.h"

#include "Collider.h"
#include "PhysicsQuad.h"

Saw::Saw(BaseScene * mod, const sf::Vector2f & position, float angle) : GameObject(mod, position, angle)
{
	//TAG
	setTag("Saw");

	//FIELDS
	m_size = sf::Vector2i(32, 16);

	//COMPONENTS
	auto render = addComponent<Renderer>();
	auto sprite = new sf::Sprite();
	sprite->setTexture(sf::Texture());
	sprite->setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
	//sprite->setOrigin(m_size.x * 0.5, m_size.y * 0.5);
	sprite->setColor(sf::Color(128,128,128));
	render->setSprite(*sprite);

	auto collider = addComponent<Collider>();
	collider->setForm(new PhysicsQuad(0, 0, m_size.x, m_size.y));
}

Saw::~Saw()
{
}

void Saw::run(float dt)
{

}

void Saw::onCollision(const GameObject & gameObject)
{
}

GameObject * Saw::clone()
{
	Saw* saw = new Saw(currentScene());
	copyComponentsTo(*saw);

	return saw;
}
