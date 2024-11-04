#include "CitySubject.h"

#include <algorithm>
#include <iostream>
#include <memory>

void CitySubject::notify() {
	for(int i=0; i<observerList.size(); i++){
		observerList[i]->update();
	}
}

void CitySubject::attach(std::shared_ptr<CitizenObserver> newObserver){
	observerList.push_back(newObserver);
}

void CitySubject::detach(std::shared_ptr<CitizenObserver> ObserverToRemove){
	auto it = std::remove(observerList.begin(), observerList.end(), ObserverToRemove);
  if (it != observerList.end()) {
    observerList.erase(it, observerList.end());
	}	
}
