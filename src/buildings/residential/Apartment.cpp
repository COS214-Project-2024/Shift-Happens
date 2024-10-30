#include "Apartment.h"
#include <iostream>

using namespace std;

Apartment::Apartment(int id)
    : ResidentialBuilding(id, 10, "Apartment", 75, 20, 100, 5, 5, 5, 5), satisfactionScore(75), capacity(10), incomePerHour(20) {}

Apartment::~Apartment(){

}

void Apartment::print() {
    cout << "Apartment Attributes:" << endl;
    cout << "Satisfaction Score: " << satisfactionScore << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Income per Hour: " << incomePerHour << endl;
    ResidentialBuilding::print(); 
}

