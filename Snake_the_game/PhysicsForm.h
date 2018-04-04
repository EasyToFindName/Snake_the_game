#pragma once

class PhysicsQuad;

class PhysicsForm {
public:
	PhysicsForm() = default;
	virtual ~PhysicsForm() = default;

	virtual PhysicsForm* clone() = 0;

	virtual bool isIntersect(const PhysicsForm& form) const = 0;
	virtual bool isIntersect(const PhysicsQuad& form) const = 0;

};