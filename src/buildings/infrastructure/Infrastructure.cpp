#include "Infrastructure.h"

int Infrastructure::getWidth() {
	return this->width;
}

void Infrastructure::setWidth(int width) {
	this->width = width;
}

int Infrastructure::getLength() {
	return this->length;
}

void Infrastructure::setLength(int length) {
	this->length = length;
}

int Infrastructure::getYPos() {
	return this->yPos;
}

void Infrastructure::setYPos(int yPos) {
	this->yPos = yPos;
}

int Infrastructure::getXPos() {
	return this->xPos;
}

void Infrastructure::setXPos(int xPos) {
	this->xPos = xPos;
}

int Infrastructure::getConstructionCost() {
	return this->constructionCost;
}

void Infrastructure::setConstructionCost(int constructionCost) {
	this->constructionCost = constructionCost;
}
