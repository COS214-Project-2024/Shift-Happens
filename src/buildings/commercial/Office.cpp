#include "Office.h"

Office::Office(int id)
: CommercialBuilding(id, 100, "Office", 50, 50, 250, 40, 40, 40, 40)
{

}

Office::~Office()
{
}

void Office::print(){
    cout << "Office Attributes:" << endl;
    CommercialBuilding::print(); // Call to CommercialBuilding's print function
}