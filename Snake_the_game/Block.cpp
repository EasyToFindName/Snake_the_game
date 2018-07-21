#include "Block.h"

#include "Collider.h"
#include "PhysicsQuad.h"

Block::Block(BaseScene * mod, const sf::Vector2f& position, float angle) : GameObject(mod, position, angle)
{
	//TAG
	setTag("Wall");

	//FIELDS
	m_size = sf::Vector2i(32, 32);

	//COMPONENTS
	auto render = addComponent<Renderer>();
	auto sprite = new sf::Sprite();
	sprite->setTexture(sf::Texture());
	sprite->setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
	//sprite->setOrigin(m_size.x * 0.5, m_size.y * 0.5);
	sprite->setColor(sf::Color::Black);
	render->setSprite(*sprite);

	auto collider = addComponent<Collider>();
	collider->setForm(new PhysicsQuad(0, 0, m_size.x, m_size.y));
}

Block::~Block()
{
}

void Block::onCollision(const GameObject & gameObject)
{
}

GameObject * Block::clone()
{
	Block* block = new Block(currentScene());
	copyComponentsTo(*block);

	return block;
}
