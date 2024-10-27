#include "Railway.h"

Railway* Railway::getNext() {
	return this->next;
}

void Railway::setNext(Railway* next) {
	this->next = next;
}

Railway* Railway::getPrev() {
	return this->prev;
}

void Railway::setPrev(Railway* prev) {
	this->prev = prev;
}
