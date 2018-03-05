#include "StaticObject.h"

StaticObject::StaticObject() : pos(Point::NO_POINT), DRAW_PRIORITY(0) {

}

StaticObject::StaticObject(const Point& p) : pos(p), DRAW_PRIORITY(0) {

}