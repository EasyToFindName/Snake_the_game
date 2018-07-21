#pragma once
#include <memory>

#include "Component.h"
#include "PhysicsForm.h"

using PhysicLayer = unsigned long;

COMPONENT(Collider)
public:
	Collider(GameObject* gameObject);
	virtual ~Collider();

	virtual Component* clone(GameObject* gameObject) override;

	void setForm(PhysicsForm* newForm);
	PhysicsForm * getForm() const;

	void update();
	void onCollision(const Collider& collider);

	void setLayer(PhysicLayer layer);
	PhysicLayer getLayer() const;


private:
	std::unique_ptr<PhysicsForm> m_form;
	PhysicLayer m_layer;

END_COMPONENT(Collider)