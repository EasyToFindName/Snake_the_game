#include "Collider.h"
#include "GameObject.h"

Collider::Collider(GameObject* gameObject) : Component(gameObject) 
{
	gameObject->currentScene()->physicsManager.addCollider(this);
	m_layer = 0;
}

Collider::~Collider()
{
	m_gameObject->currentScene()->physicsManager.removeCollider(this);
}

Component * Collider::clone(GameObject * gameObject)
{
	Collider* component = new Collider(gameObject);

	component->setForm(m_form.get()->clone());
	component->setLayer(m_layer);

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

void Collider::setLayer(PhysicLayer layer)
{
	m_layer = layer;
}

PhysicLayer Collider::getLayer() const
{
	return m_layer;
}
