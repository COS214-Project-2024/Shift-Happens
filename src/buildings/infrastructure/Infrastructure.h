#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include "../../map/MapComponent.h"
class Infrastructure : public MapComponent
{

private:
	int width;
	int length;
	int yPos;
	int xPos;
	int constructionCost;

public:
	int getWidth();

	void setWidth(int width);

	int getLength();

	void setLength(int length);

	int getYPos();

	void setYPos(int yPos);

	int getXPos();

	void setXPos(int xPos);

	int getConstructionCost();

	void setConstructionCost(int constructionCost);
};

#endif
