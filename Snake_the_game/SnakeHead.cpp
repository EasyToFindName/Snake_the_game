#include "SnakeHead.h"
#include "Collider.h"
#include "PhysicsQuad.h"


SnakeHead::SnakeHead(BaseScene* mod, const sf::Vector2f& position, float angle) : GameObject(mod, position, angle)
{
	//TAG
	setTag("Snake");

	//FIELDS
	m_startPos = sf::Vector2f(128, 128);
	m_size = sf::Vector2i(32, 32);
	m_speed = 10.0f;
	m_rotateSpeed = 10.0f;
	m_smoothFactor = 0.04f;

	//COMPONENTS
	transform()->setPosition(m_startPos);

	auto render = addComponent<Renderer>();
	auto sprite = new sf::Sprite();
	sprite->setTexture(sf::Texture());
	sprite->setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));
	sprite->setOrigin(m_size.x * 0.5, m_size.y * 0.5);
	sprite->setColor(sf::Color::Red);
	render->setSprite(*sprite);

	auto collider = addComponent<Collider>();
	collider->setForm(new PhysicsQuad(0, 0, m_size.x, m_size.y));

	//TAILS
	addTail(3);
}

SnakeHead::~SnakeHead()
{
}

void SnakeHead::processKey(const sf::Keyboard::Key & key)
{
	switch (key) {
	case sf::Keyboard::W:
		
		break;
	case sf::Keyboard::A:
		transform()->rotate(-m_rotateSpeed);
		break;
	case sf::Keyboard::S:
		
		break;
	case sf::Keyboard::D:
		transform()->rotate(m_rotateSpeed);
		break;
	case sf::Keyboard::F:
		addTail(1);
		break;
	case sf::Keyboard::T:
		transform()->setPosition(200, 200);
		break;
	}
}

void SnakeHead::run(float dt)
{
	for (auto& tail : m_tails) {
		tail->move(m_smoothFactor * m_speed * dt, m_smoothFactor * m_rotateSpeed * dt);
	}
	move(m_speed * dt);
}

void SnakeHead::onCollision(const GameObject & gameObject)
{
	if (gameObject.getTag() == "Apple") {
		addTail(1);
	}
}

GameObject * SnakeHead::clone()
{
	SnakeHead* head = new SnakeHead(currentScene());
	copyComponentsTo(*head);

	return head;
}

void SnakeHead::move(float speed)
{
	sf::Vector2f dir = 
	{
		cos(transform()->getRotation() / 180.0f * 3.14f) * speed,
		sin(transform()->getRotation() / 180.0f * 3.14f) * speed 
	};

	transform()->move(dir);
}

void SnakeHead::addTail(int count)
{
	for (int i = 0; i < count; i++) {
		auto tail = currentScene()->Instantiate<SnakeTail>();

		if (m_tails.empty()) {
			/*sf::Vector2f offset =
			{
				cos(transform()->getRotation() / 180.0f * 3.14f) * m_size.x,
				sin(transform()->getRotation() / 180.0f * 3.14f) * m_size.y
			};*/

			tail->transform()->setPosition(transform()->getPosition()/* - offset*/); 
			tail->transform()->setRotation(transform()->getRotation());

			tail->setTarget(transform());
		}
		else {
			/*sf::Vector2f offset =
			{
				cos(m_tails.back()->transform()->getRotation() / 180.0f * 3.14f) * m_size.x,	//size ?
				sin(m_tails.back()->transform()->getRotation() / 180.0f * 3.14f) * m_size.y
			};*/

			tail->transform()->setPosition(m_tails.back()->transform()->getPosition()/* - offset*/);
			tail->transform()->setRotation(m_tails.back()->transform()->getRotation());

			tail->setTarget(m_tails.back()->transform());
		}

		m_tails.push_back(tail);
	}
}
