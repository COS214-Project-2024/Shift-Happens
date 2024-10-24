#include "Road.h"

Building_State::Road* Building_State::Road::getNext() {
	return this->next;
}

void Building_State::Road::setNext(Building_State::Road* next) {
	this->next = next;
}

Building_State::Road* Building_State::Road::getPrev() {
	return this->prev;
}

void Building_State::Road::setPrev(Building_State::Road* prev) {
	this->prev = prev;
}
