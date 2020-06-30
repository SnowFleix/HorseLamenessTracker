#include "object.h"

Object::Object() { }

Object::~Object(void) { }

int Object::getXPos() {
    return Object::xPos;
}

void Object::setXPos(int x) {
    Object::xPos = x;
}

int Object::getYPos() {
    return Object::yPos;
}

void Object::setYPos(int y) {
    Object::yPos = y;
}
