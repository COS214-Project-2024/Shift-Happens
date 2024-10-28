#include "Citizen.h"

void Citizen::update(){
  observerPopulation = economy->getState();
  observerPublicServiceState = infrastructure->getState();
  observerTax = government->getTax();
  observerPolicy = government->getPolicies();
}