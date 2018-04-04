#pragma once
#include <memory>

#include "Component.h"
#include "PhysicsForm.h"

COMPONENT(Collider)
public:
	Collider(GameObject* gameObject);
	virtual ~Collider();

	virtual Component* clone(GameObject* gameObject) override;

	void setForm(PhysicsForm* newForm);
	PhysicsForm * getForm() const;

private:
	std::unique_ptr<PhysicsForm> m_form;

END_COMPONENT(Collider)