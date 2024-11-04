#include "Government.h"
#include "../citizens/ManBuilder.h"
#include "../citizens/WomanBuilder.h"
#include "../citizens/BoyBuilder.h"
#include "../citizens/GirlBuilder.h"
#include "UnderPopulated.h"

#include <algorithm>
#include <memory>
#include <iostream>

Government::Government() {
    //CitizenDirector = make_shared<Director>();
    // Initially set tax states
    this->AvailableSpendingBudget = 150000; // Initial budget

    // Initialize the public services
    // Initially public services states will be at the worst
    education = std::make_shared<Education>();
    education->setPublicServiceState(make_shared<Outdated>(education));

    healthcare = std::make_shared<HealthCare>();
    healthcare->setPublicServiceState(make_shared<Outdated>(healthcare));

    police = std::make_shared<Police>();
    police->setPublicServiceState(make_shared<Outdated>(police));

    economy = std::make_shared<Economy>();
    economy->setPopulationState(make_shared<UnderPopulated>());

    // Now that the public services are initialized, create the policies
    AvailablePolicies.push_back(std::make_shared<BoostEducationPolicy>(education));
    AvailablePolicies.push_back(std::make_shared<BoostHealthCarePolicy>(healthcare));
    AvailablePolicies.push_back(std::make_shared<BoostPolicePolicy>(police));

    ManCitizenDirector = std::make_shared<Director>(std::make_shared<ManBuilder>());
    WomanCitizenDirector = std::make_shared<Director>(std::make_shared<WomanBuilder>());
    BoyCitizenDirector = std::make_shared<Director>(std::make_shared<BoyBuilder>());
    GirlCitizenDirector = std::make_shared<Director>(std::make_shared<GirlBuilder>());
}

double Government::getPersonalTaxRate(){
    return this->PersonalTaxRate;
}

double Government::getBusinessTaxRate(){
    return this->BusinessTaxRate;
}

double Government::setPersonalTaxRate(double rate){
    this->PersonalTaxRate = rate;
    return this->PersonalTaxRate;
}

double Government::setBusinessTaxRate(double rate){
    this->BusinessTaxRate = rate;
    return this->BusinessTaxRate;
}

void Government::setPersonalTaxLower(double decrease) {
	PersonalTaxState->lower(decrease);
	this->PersonalTaxRate = PersonalTaxState->getRate();
}

void Government::setPersonalTaxHigher(double increase) {
    //cout << "Entered government higher" << endl;
	PersonalTaxState->higher(increase);
	this->PersonalTaxRate = PersonalTaxState->getRate();
    //cout << "Exited government" << endl;
}

// Helper function to convert strings to lowercase
std::string Government::toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void Government::addExecutePolicy(string policyType) {

    std::string lowerPolicy = toLowerCase(policyType);
    bool success = false;
    for (const auto& policy : AvailablePolicies) {
        if (toLowerCase(policy->getPolicyType()) == lowerPolicy) {
            ImplementedPolicies.push_back(policy);
            policy->executePolicy();
            success = true;
            break;

        }
    }
    if (success == false) {
        throw "Government::addExecutePolicy() invalid policy: " + policyType;
    }
    
    //remove the policy from the available policies
    for (std::vector<std::shared_ptr<Policy>>::size_type i = 0; i < AvailablePolicies.size(); i++) {
        if (toLowerCase(AvailablePolicies[i]->getPolicyType()) == lowerPolicy) {
            AvailablePolicies.erase(AvailablePolicies.begin() + i);
            success = true;
            break;
        }
    }
}


double Government::getUnemployment(){
    int Total = 0;
    int NotEmployed = 0;
    for(shared_ptr<Citizen> temp: CitizenCollection){
        //cout << "Entered" << endl;
        if(temp->getDescription() == "Man Citizen" || temp->getDescription() == "Woman Citizen"){
            Total++;
            //cout << "Entered" << endl;
            if(temp->getStatus()){
                
            } else {
                NotEmployed++;
            }
        }
    }
    // cout <<"Total parents: "<< Total << endl;
    // cout << "Total emplyed: "<<NotEmployed << endl;
    if (Total == 0) return 0.0;

    return (static_cast<double>(Total - NotEmployed) / Total) * 100;
}

double Government::getSchoolStats(){
    int Total = 0;
    int notinSchool = 0;
    for(shared_ptr<Citizen> temp: CitizenCollection){
        if(temp->getDescription() == "Boy Citizen" || temp->getDescription() == "Girl Citizen"){
            Total++;
            if(temp->getStatus()){
                
            } else {
                notinSchool++;
            }
        }
    }
    // cout <<"Total kids: "<< Total << endl;
    // cout << "Total school: "<<notinSchool << endl;
    if (Total == 0) return 0.0;
    return (static_cast<double>(Total - notinSchool) / Total) * 100;
}

void Government::setTaxState(std::shared_ptr<Tax> tax){
	this->PersonalTaxState = tax;
    cout << "notified citizen" << endl;
	this->notify();
}

std::shared_ptr<Tax> Government::getTax(){
	return PersonalTaxState;
}

std::vector<std::shared_ptr<Policy>> Government::getCurrentPolicies(){
	return ImplementedPolicies;
}

std::shared_ptr<Tax> Government::getBusinessTax(){
	return BusinessTaxState;
}

void Government::setBusinessTaxState(std::shared_ptr<Tax> tax){
	this->BusinessTaxState = tax;
}

void Government::setBusinessTaxHigher(double increase){
	BusinessTaxState->higherBusiness(increase);
	this->BusinessTaxRate = BusinessTaxState->getBusinessRate();
}

void Government::setBusinessTaxLower(double decrease){
	BusinessTaxState->lowerBusiness(decrease);
	this->BusinessTaxRate = BusinessTaxState->getBusinessRate();
}

double Government::getAvailableSpendingBudget(){
	return AvailableSpendingBudget;
}


std::shared_ptr<Education> Government::getEducation() const{
    return education;
}

std::shared_ptr<HealthCare> Government::getHealthCare() const{
    return healthcare;
}

std::shared_ptr<Police> Government::getPolice() const{
    return police;
}

void Government::removeCitizen(){
    if (CitizenCollection.size() == 0)
    {
        return;
    }
    
    CitizenCollection.pop_back();
}

void Government::addCitizen(){
    std::string Answer = "";
    string boy = "boy";
    string man = "man";
    string woman = "woman";
    string girl = "girl";

    int randomValue = (rand() % 4) + 1;

    if(this->citizenTypeCounter == 0){
        Answer = "Boy";
        citizenTypeCounter++;
    }
    else if(this->citizenTypeCounter == 1){
        Answer = "Girl";
        citizenTypeCounter++;
    }
    else if(this->citizenTypeCounter == 2){
        Answer = "Man";
        citizenTypeCounter++;
    }
    else if(this->citizenTypeCounter == 3){
        Answer = "Woman";
        citizenTypeCounter = 0;
    }


    std::shared_ptr<Government> self = shared_from_this();
        

        if (Answer == "Man") {  
            
            ManCitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = ManCitizenDirector->getBuilder()->getCitizen();
            newCitizen->setEconomy(economy);
            newCitizen->setPolice(police);
            newCitizen->setEducation(education);
            newCitizen->setHealthcare(healthcare);
            newCitizen->setGovernment(self);

            CitizenCollection.push_back(newCitizen);
            police->attach(newCitizen);
            education->attach(newCitizen);
            healthcare->attach(newCitizen);
            economy->attach(newCitizen);
            this->attach(newCitizen);
            
        } else if (Answer == "Woman") {
            WomanCitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = WomanCitizenDirector->getBuilder()->getCitizen();
            newCitizen->setEconomy(economy);
            newCitizen->setPolice(police);
            newCitizen->setEducation(education);
            newCitizen->setHealthcare(healthcare);
            newCitizen->setGovernment(self);

            CitizenCollection.push_back(newCitizen);

            police->attach(newCitizen);
            education->attach(newCitizen);
            healthcare->attach(newCitizen);
            economy->attach(newCitizen);
            this->attach(newCitizen);
        } else if (Answer == "Boy") {
            BoyCitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = BoyCitizenDirector->getBuilder()->getCitizen();
            newCitizen->setEconomy(economy);
            newCitizen->setPolice(police);
            newCitizen->setEducation(education);
            newCitizen->setHealthcare(healthcare);
            newCitizen->setGovernment(self);

            CitizenCollection.push_back(newCitizen);

            police->attach(newCitizen);
            education->attach(newCitizen);
            healthcare->attach(newCitizen);
            economy->attach(newCitizen);
            this->attach(newCitizen);
        } else if (Answer == "Girl") {
            GirlCitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = GirlCitizenDirector->getBuilder()->getCitizen();
            newCitizen->setEconomy(economy);
            newCitizen->setPolice(police);
            newCitizen->setEducation(education);
            newCitizen->setHealthcare(healthcare);
            newCitizen->setGovernment(self);

            CitizenCollection.push_back(newCitizen);

            police->attach(newCitizen);
            education->attach(newCitizen);
            healthcare->attach(newCitizen);
            economy->attach(newCitizen);
            this->attach(newCitizen);
        } else {
            std::cout << "Invalid input. Please enter one of the following: Man, Woman, Boy, or Girl." << std::endl;
        }
}


void Government::addCitizen(std::shared_ptr<Citizen> newCitizen){
    CitizenCollection.push_back(newCitizen);
}

double Government::CollectPersonalTax(){
    double incomeTax;
    for(shared_ptr<Citizen> temp: CitizenCollection){
        if(temp->getDescription() != "Man" || temp->getDescription() != "Woman"){
            incomeTax += temp->getIncome() * this->PersonalTaxRate/100;
        }
    }

    return incomeTax;
}

double Government::getSatisfaction() {
    double Satisfaction = 0.0;
    int count = CitizenCollection.size();

    if (count == 0) {
        //cout << "Citizen empty" << endl;
        return 0.0;
    }

    for (shared_ptr<Citizen> temp : CitizenCollection) {
        double score = temp->getSatisfactionScore();
        //cout << "Returned score" << score << endl;
        if (std::isnan(score)) {
            //cout << "Entered Nan" << endl;
            continue; 
        }
        Satisfaction += score;
    }   
    //cout << "Satisfaction" << Satisfaction << endl;
    return Satisfaction / count;
}

void Government::setPeopleCount(int count, int BusinessSatisfaction) {
    double satisfaction = getSatisfaction();
    double CombinedSatisfaction = (BusinessSatisfaction + satisfaction) / 2;
    
    if (CombinedSatisfaction <= 0) { 
        this->PopulationCount = 0; 
        return;
    }

    int ActualPopulation = static_cast<int>(count * CombinedSatisfaction/100);
    this->PopulationCount = ActualPopulation;
    this->CombinedSatisfaction = CombinedSatisfaction;


    if(static_cast<std::vector<std::shared_ptr<Citizen>>::size_type>(PopulationCount) > CitizenCollection.size()){
        // create citizens
        //cout << "Entered add citizens" << endl;
        int Difference = PopulationCount - CitizenCollection.size();
        for(int i=0; i<Difference; i++){
            addCitizen();
            economy->increasePop(1);
        } 
    }

    if(PopulationCount < CitizenCollection.size()){
        int Difference = CitizenCollection.size() - PopulationCount;
        for(int i=0; i<Difference; i++){
            removeCitizen();
            economy->decreasePop(1);
        }
    }

}

double Government::getCombinedSatisfaction(){
    return CombinedSatisfaction;
}


int Government::getPeopleCount(){
    return this->PopulationCount;
}

double Government::CollectBusinessTax(int numBusinesses){
    double businessTax = 0;
    for(int i = 0; i < numBusinesses; i++){
        businessTax +=  this->BusinessTaxRate;
    }

    return businessTax;
}

double Government::getIncome(){
    throw "Government::getIncome() not implemented";
}

void Government::IncreaseAvialableBudget(double increase){
    this->AvailableSpendingBudget += increase;
}

std::vector<std::shared_ptr<Policy>> Government::getAvailablePolicies(){
    return AvailablePolicies;
}
