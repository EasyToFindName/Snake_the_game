#pragma once

#include "ComponentCounter.h"

namespace ComponentType {
	unsigned count();
};

#define _IMPL_CONCAT(x, y) x##y
#define _MACRO_CONCAT(x, y) _IMPL_CONCAT(x, y)

#define _INC_COMPONENT_COUNTER(unique_id) namespace {_ComponentCounter _MACRO_CONCAT(counter, unique_id);}
#define _COMPONENT_COUNT _ComponentCounter::getCounter();

#define _ADD_COMPONENT_NAME(id, value) namespace ComponentType { const unsigned int id = value;}
#define _GET_COMPONENT_NAME(id) ComponentType::id;

#define _REGISTER_COMPONENT(id) _INC_COMPONENT_COUNTER(id) \
								_ADD_COMPONENT_NAME(id, _COMPONENT_COUNT)
#define _GENERATE_COMPONENT_BODY(id) public: virtual unsigned getType() override { return _GET_COMPONENT_NAME(id); } \
								     public: static unsigned getId() { return _GET_COMPONENT_NAME(id); }

#define COMPONENT(x) _REGISTER_COMPONENT(x) \
				class x : public Component { \
				_GENERATE_COMPONENT_BODY(x)

#define COMPONENT_DERIVED_FROM_CLASS(x, Class) _REGISTER_COMPONENT(x) \
				class x : public Component, public Class { \
				_GENERATE_COMPONENT_BODY(x)

#define COMPONENT_DERIVED_FROM_COMPONENT(x, OtherComponent) _REGISTER_COMPONENT(x) \
				class x : public OtherComponent { \
				_GENERATE_COMPONENT_BODY(x)

#define END_COMPONENT };