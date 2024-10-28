#ifndef RAILWAY_H
#define RAILWAY_H
#include "Infrastructure.h"

	class Railway : public Infrastructure {

	private:
		Railway* next;
		Railway* prev;

	public:
		Railway* getNext();

		void setNext(Railway* next);

		Railway* getPrev();

		void setPrev(Railway* prev);
	};

#endif
