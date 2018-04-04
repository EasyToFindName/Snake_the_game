#include "Module.h"
#include "Module.h"



Module::Module(Module* parent) : m_parent(parent) 
{

}

Module::~Module() 
{

}

void Module::physicsUpdate()
{
	physicsManager.update();
}

