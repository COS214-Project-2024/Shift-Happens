#ifndef ROAD_H
#define ROAD_H
#include "Infrastructure.h"
	class Road :public Infrastructure {

	private:
		Road* next;
		Road* prev;

	public:
		Road* getNext();

		void setNext(Road* next);

		Road* getPrev();

		void setPrev(Road* prev);
	};

#endif
