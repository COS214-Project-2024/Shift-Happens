#include <iostream>
#include <memory>
#include <vector>

//Policies
#include "../Government/PublicServiceState.h"
#include "../Government/Standard.h"
#include "../Government/Outdated.h"
#include "../Government/Modern.h"
#include "../Government/PublicServices.h"
#include "../Government/CitySubject.h"
#include "../citizens/CitizenObserver.h"
#include "../Government/Education.h"
#include "../Government/HealthCare.h"
#include "../Government/Police.h"
#include "../Government/BoostEducationPolicy.h"
#include "../Government/BoostHealthCarePolicy.h"
#include "../Government/BoostPolicePolicy.h"
#include "../Government/Policy.h"
#include "../Government/Government.h"

//Taxes
#include "../Government/Tax.h"
#include "../Government/LowTax.h"
#include "../Government/StandardTax.h"
#include "../Government/HighTax.h"

#include "../Statistics.h"
#include "../Government/Tax.h"

using namespace std;


int main(){

    
    //cout << "Hello World!" <<endl;

    cout<<"Creating a government..."<<endl;
    shared_ptr<Government> government = make_shared<Government>();
    cout<<"Government successfully created..."<<endl;

    

    return 0;
}