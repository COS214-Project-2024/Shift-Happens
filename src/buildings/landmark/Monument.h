#ifndef MONUMENT_H
#define MONUMENT_H

#include "LandMark.h"
class Monument : public LandMark {
	
public:
    Monument(int id);
    ~Monument();

    void print();
    
};


#endif
