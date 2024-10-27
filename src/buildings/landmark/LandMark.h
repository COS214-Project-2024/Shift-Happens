#ifndef LANDMARK_H
#define LANDMARK_H

#include "../Building.h"
class LandMark : public Building
{

public:
	int satisfactionScore;

	int getSatisfactionScore();

	void setSatisfactionScore(int satisfactionScore);
};

#endif
