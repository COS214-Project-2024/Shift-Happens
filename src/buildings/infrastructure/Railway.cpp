#include "Railway.h"

Building_State::Railway* Building_State::Railway::getNext() {
	return this->next;
}

void Building_State::Railway::setNext(Building_State::Railway* next) {
	this->next = next;
}

Building_State::Railway* Building_State::Railway::getPrev() {
	return this->prev;
}

void Building_State::Railway::setPrev(Building_State::Railway* prev) {
	this->prev = prev;
}
