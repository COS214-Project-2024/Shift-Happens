#ifndef BUILDING_H
#define BUILDING_H

#include <string>

using namespace std;
class Building 
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

public:
	int getWidth();

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
};

#endif
