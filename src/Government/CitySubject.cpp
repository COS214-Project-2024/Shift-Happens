#include "CitySubject.h"

#include <algorithm>

void CitySubject::notify() {
	for(int i=0; i<observerList.size(); i++){
		observerList[i]->update();
	}
}

void CitySubject::attach(CitizenObserver* newObserver){
	observerList.push_back(newObserver);
}

void CitySubject::detach(CitizenObserver* ObserverToRemove){
	auto it = std::remove(observerList.begin(), observerList.end(), ObserverToRemove);
  if (it != observerList.end()) {
    observerList.erase(it, observerList.end());
	}	
}
