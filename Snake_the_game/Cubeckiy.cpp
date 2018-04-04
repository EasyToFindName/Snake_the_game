#include "Cubeckiy.h"
#include "Collider.h"
#include "PhysicsQuad.h"

Cubeckiy::Cubeckiy(Module* mod) : GameObject(mod)
{
	addComponent<Renderer>();

	auto collider = addComponent<Collider>();
	collider->setForm(new PhysicsQuad(0, 0, 32, 32));
}


Cubeckiy::~Cubeckiy()
{
}

GameObject * Cubeckiy::clone()
{
	Cubeckiy* cube = new Cubeckiy(currentModule());
	copyComponentsTo(*cube);

	return cube;
}
