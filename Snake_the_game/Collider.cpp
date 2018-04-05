#include "Collider.h"
#include "GameObject.h"

Collider::Collider(GameObject* gameObject) : Component(gameObject) 
{
	gameObject->currentModule()->physicsManager.addCollider(this);
}

Collider::~Collider()
{
	m_gameObject->currentModule()->physicsManager.removeCollider(this);
}

Component * Collider::clone(GameObject * gameObject)
{
	Collider* component = new Collider(gameObject);

	component->setForm(m_form.get()->clone());

	return component;
}

void Collider::setForm(PhysicsForm* newForm)
{
	m_form.reset(newForm);
}

PhysicsForm * Collider::getForm() const
{
	return m_form.get();
}

void Collider::update()
{
	m_form->update(m_gameObject->transform()->getPosition());
}

void Collider::onCollision(const Collider & collider)
{
	m_gameObject->onCollision(*collider.m_gameObject);
}
