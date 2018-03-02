#pragma once

#include "StaticObject.h"
#include "DynamicObject.h"

#include <vector>
#include <memory>

class Level {
public:
	Level();
	~Level();
private:
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	std::vector<std::unique_ptr<DynamicObject>> m_dynamicObjects;
};

