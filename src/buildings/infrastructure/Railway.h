#ifndef RAILWAY_H
#define RAILWAY_H

namespace Building_State {
	class Railway : Building_State::Infrastructure {

	private:
		Building_State::Railway* next;
		Building_State::Railway* prev;

	public:
		Building_State::Railway* getNext();

		void setNext(Building_State::Railway* next);

		Building_State::Railway* getPrev();

		void setPrev(Building_State::Railway* prev);
	};
}

#endif
