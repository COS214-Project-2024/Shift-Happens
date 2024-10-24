#include "Infrastructure.h"

int Building_State::Infrastructure::getWidth() {
	return this->width;
}

void Building_State::Infrastructure::setWidth(int width) {
	this->width = width;
}

int Building_State::Infrastructure::getLength() {
	return this->length;
}

void Building_State::Infrastructure::setLength(int length) {
	this->length = length;
}

int Building_State::Infrastructure::getYPos() {
	return this->yPos;
}

void Building_State::Infrastructure::setYPos(int yPos) {
	this->yPos = yPos;
}

int Building_State::Infrastructure::getXPos() {
	return this->xPos;
}

void Building_State::Infrastructure::setXPos(int xPos) {
	this->xPos = xPos;
}

int Building_State::Infrastructure::getConstructionCost() {
	return this->constructionCost;
}

void Building_State::Infrastructure::setConstructionCost(int constructionCost) {
	this->constructionCost = constructionCost;
}
