#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include "../map/MapComponent.h"

using namespace std;
class Building : public MapComponent
{

private:
	int width;
	int xPos;
	int yPos;
	int constructionPrice;
	int length;
	string variant;
	string type;
	int wasteProduced;
	int sewageProduced;
	int electricityDemand;
	int waterDemand;

protected:

public:
	Building(int id,int width, int length, int xPos, int yPos, string variant, string type, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);
	int getWidth();

	bool add(MapComponent *component);
	bool remove(MapComponent *component);
	void getComponent(int id);
	void render();

	void setWidth(int width);

	int getLength();

	void setLength(int length);

	int getXPos();

	void setXPos(int xPos);

	int getYPos();

	void setYPos(int yPos);

	string getVariant();

	void setVariant(string variant);

	string getType();

	void setType(string type);

	int getConstructionPrice();

	void setConstructionPrice(int constructionPrice);

	int getWasteProduced();

	void setWasteProduced(int wasteProduced);

	int getSewageProduced();

	void setSewageProduced(int sewageProduced);

	int getElectricityDemand();

	void setElectricityDemand(int electricityDemand);

	int getWaterDemand();

	void setWaterDemand(int waterDemand);

	//print function:
	virtual void print() const;
};

#endif
