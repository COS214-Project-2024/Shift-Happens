#include "Road.h"

Road* Road::getNext() {
	return this->next;
}

void Road::setNext(Road* next) {
	this->next = next;
}

Road* Road::getPrev() {
	return this->prev;
}

void Road::setPrev(Road* prev) {
	this->prev = prev;
}
