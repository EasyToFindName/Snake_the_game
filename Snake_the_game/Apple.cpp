#include "Apple.h"

#include "Collider.h"
#include "PhysicsQuad.h"

Apple::Apple(BaseScene * mod) : GameObject(mod)
{
	//TAG
	setTag("Apple");

	//FIELDS
	m_size = sf::Vector2i(16, 16);

	//COMPONENTS
	auto render = addComponent<Renderer>();
	auto sprite = new sf::Sprite();
	sprite->setTexture(sf::Texture());
	sprite->setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
	sprite->setOrigin(m_size.x * 0.5, m_size.y * 0.5);
	sprite->setColor(sf::Color::Blue);
	render->setSprite(*sprite);

	auto collider = addComponent<Collider>();
	collider->setForm(new PhysicsQuad(0, 0, m_size.x, m_size.y));

	changePosition();
}

Apple::~Apple()
{
}

void Apple::onCollision(const GameObject & gameObject)
{
	if (gameObject.getTag() == "Snake") {
		changePosition();
	}
}

GameObject * Apple::clone()
{
	Apple* apple = new Apple(currentScene());
	copyComponentsTo(*apple);

	return apple;
}

void Apple::changePosition()
{
	sf::Vector2f position;
	do {
		position.x =  m_rand.generateInt(0, 400); //TO DO
		position.y =  m_rand.generateInt(0, 400);
	} while (!currentScene()->physicsManager.isPointFree(position));

	transform()->setPosition(position);
}
