#include "Office.h"

Office::Office(int id, string name, int incomePerHour, string variant, int satisfactionScore, int numberOfEmployees, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand)
: CommercialBuilding(id, name, incomePerHour, variant, satisfactionScore, numberOfEmployees, constructionPrice, wasteProduced, sewageProduced, electricityDemand, waterDemand)
{
    
}