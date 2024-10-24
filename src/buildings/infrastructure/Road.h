#ifndef ROAD_H
#define ROAD_H

namespace Building_State {
	class Road : Building_State::Infrastructure {

	private:
		Building_State::Road* next;
		Building_State::Road* prev;

	public:
		Building_State::Road* getNext();

		void setNext(Building_State::Road* next);

		Building_State::Road* getPrev();

		void setPrev(Building_State::Road* prev);
	};
}

#endif
