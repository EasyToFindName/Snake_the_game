#pragma once

#include <cstddef>
template<size_t n>
struct cn {
	char data[n + 1];
};

template<typename id, size_t index, size_t val>
cn<val> magic(id, cn<index>, cn<val>);

#define counter_read(id) \
    (sizeof( \
        magic(id(), cn<1>(), \
        magic(id(), cn<2>(), \
        magic(id(), cn<4>(), \
        magic(id(), cn<8>(), \
        magic(id(), cn<16>(), \
        magic(id(), cn<32>(), \
        magic(id(), cn<64>(), \
        magic(id(), cn<128>(), cn<0>())))))))))-1)

#define counter_inc(id) \
    cn<counter_read(id)+1> magic(id, \
        cn<(counter_read(id)+1)&~counter_read(id)>, \
        cn<(counter_read(id)+1)&counter_read(id)>)

struct current_counter {};


template<unsigned N>
struct marker_id {
	static unsigned const value = N;
};

template<typename T>
struct marker_type { using type = T; };

template<typename T, unsigned N>
struct register_id : marker_id<N>, marker_type<T> {
};

template<typename T>
struct component_map;


#define COMPONENT_MAX counter_read(current_counter)
#define COMPONENT_VALUE(X) component_map<X>::value


#define _REGISTER_COMPONENT(X) template<> struct component_map<X> : register_id<X, counter_read(current_counter)> { }; \
							   counter_inc(current_counter);

#define COMPONENT(x) class x : public Component {

#define COMPONENT_DERIVED_FROM_CLASS(x, Class) class x : public Component, public Class { 

#define COMPONENT_DERIVED_FROM_COMPONENT(x, OtherComponent) class x : public OtherComponent { 

#define END_COMPONENT(X) }; _REGISTER_COMPONENT(X)