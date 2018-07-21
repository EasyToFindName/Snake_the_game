#include "Transform.h"

Transform::Transform(GameObject * gameObject) : Component(gameObject)
{

}

Transform::~Transform()
{
}

Component * Transform::clone(GameObject* gameObject)
{
	Transform* component = new Transform(gameObject);
	
	component->setPosition(getPosition());
	component->setRotation(getRotation());
	component->setScale(getScale());

	return component;
}
