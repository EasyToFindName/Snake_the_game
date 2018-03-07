#pragma once

class GameObject;

enum class COMPONENT {TRANSFORM, RENDERER, END};

class Component {
public:
	Component(GameObject* gameObject);

	Component(const Component&) = delete;
	void operator=(const Component&) = delete;

	virtual ~Component() = default;


	static COMPONENT getID();

protected:
	GameObject* m_gameObject;
};