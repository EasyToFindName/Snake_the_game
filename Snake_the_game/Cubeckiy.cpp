#include "Cubeckiy.h"



Cubeckiy::Cubeckiy(Module* mod) : GameObject(mod)
{
	addComponent<Renderer>();
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
