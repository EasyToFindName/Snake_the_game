#pragma once
#include "GameObject.h"

class Cubeckiy : public GameObject
{
public:
	Cubeckiy(Module* mod);
	~Cubeckiy();

	virtual void onCollision(const GameObject& gameObject) override;
	virtual GameObject* clone() override;
};

