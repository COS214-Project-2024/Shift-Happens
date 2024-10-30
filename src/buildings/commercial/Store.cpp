#include "Store.h"

Store::Store(int id)
: CommercialBuilding(id, 50, "Store", 50, 25, 125, 10, 10, 10, 10)
{

}

Store::~Store()
{
}

void Store::print()
{
    cout << "Store Attributes:" << endl;
    CommercialBuilding::print(); // Call to CommercialBuilding's print function
}