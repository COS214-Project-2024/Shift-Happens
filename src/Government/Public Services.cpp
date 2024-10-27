#include "Public Services.h"

void Public_Services::DelegateFunds(){

}

void Public_Services::setPublicServiceState(PublicServiceState* newState){
  delete this->InfraStructureCondition;
  this->InfraStructureCondition = newState;
}