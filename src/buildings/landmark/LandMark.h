#ifndef LANDMARK_H
#define LANDMARK_H

#include "../Building.h"
class LandMark : public Building
{

protected:
	string variant;
	int satisfactionScore;

public:
	LandMark(int id, string variant, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand, int satisfactionScore);

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);

	void render();

	bool add(MapComponent *component);

	bool remove(MapComponent *component);

	void getComponent(int id);

	void print();

	~LandMark();

};

#endif
