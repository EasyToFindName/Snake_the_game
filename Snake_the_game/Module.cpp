#include "Module.h"
#include "Module.h"

#include "GameObject.h"


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

void Module::Destroy(GameObject * obj)
{
	for (auto it = m_gameObjects.begin(); it != m_gameObjects.end(); it++) {
		if (it->get() == obj) {
			m_gameObjects.erase(it);
			return;
		}
	}
}

