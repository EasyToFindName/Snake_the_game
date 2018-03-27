#pragma once
#include "GameObject.h"

class Cubeckiy : public GameObject
{
public:
	Cubeckiy(Module* mod);
	~Cubeckiy();


	virtual GameObject* clone() override;
};

