#include "Government.h"
#include "../citizens/ManBuilder.h"
#include "../citizens/WomanBuilder.h"
#include "../citizens/BoyBuilder.h"
#include "../citizens/GirlBuilder.h"

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

    // Now that the public services are initialized, create the policies
    AvailablePolicies.push_back(std::make_shared<BoostEducationPolicy>(education));
    AvailablePolicies.push_back(std::make_shared<BoostHealthCarePolicy>(healthcare));
    AvailablePolicies.push_back(std::make_shared<BoostPolicePolicy>(police));



}

double Government::getPersonalTaxRate(){
    return this->PersonalTaxRate;
}

double Government::getBusinessTaxRate(){
    return this->BusinessTaxRate;
}

double Government::setPersonalTaxRate(double rate){
    this->PersonalTaxRate = rate;
}

double Government::setBusinessTaxRate(double rate){
    this->BusinessTaxRate = rate;
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
    for (int i = 0; i < AvailablePolicies.size(); i++) {
        if (toLowerCase(AvailablePolicies[i]->getPolicyType()) == lowerPolicy) {
            AvailablePolicies.erase(AvailablePolicies.begin() + i);
            success = true;
            break;
        }
    }
}




void Government::setTaxState(std::shared_ptr<Tax> tax){
	this->PersonalTaxState = tax;
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
    CitizenCollection.pop_back();
}

void Government::addCitizen(){
    //CitizenDirector->construct();
    std::string Answer;
    std::cout << "Specify the type of citizen you would like to add: Man/Woman/Boy/Girl" << std::endl;

    while (true) {
        std::cin >> Answer;

        if (Answer == "Man" || Answer == "man") {  
            CitizenDirector.reset();
            CitizenDirector = std::make_shared<Director>(std::make_shared<ManBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else if (Answer == "Woman" || Answer == "woman") {
            CitizenDirector.reset();
            CitizenDirector = std::make_shared<Director>(std::make_shared<WomanBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else if (Answer == "Boy" || Answer == "boy") {
            CitizenDirector.reset();
            CitizenDirector = std::make_shared<Director>(std::make_shared<BoyBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else if (Answer == "Girl" || Answer == "girl") {
            CitizenDirector.reset();
            CitizenDirector = std::make_shared<Director>(std::make_shared<GirlBuilder>());
            CitizenDirector->construct();
            std::shared_ptr<Citizen> newCitizen = CitizenDirector->getBuilder()->getCitizen();
            CitizenCollection.push_back(newCitizen);
            break;
        } else {
            std::cout << "Invalid input. Please enter one of the following: Man, Woman, Boy, or Girl." << std::endl;
        }
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

// double Government::getSatisfaction(){
//     double Satisfaction =0;
//     int count = CitizenCollection.size();
//     for(shared_ptr<Citizen> temp: CitizenCollection){
//         Satisfaction += temp->getSatisfactionScore();
//     }

//     return Satisfaction/count;
// }

double Government::getSatisfaction() {
    double Satisfaction = 0.0; // Initialize to zero
    int count = CitizenCollection.size();

    // If there are no citizens, return 0.0 to avoid division by zero
    if (count == 0) {
        std::cout << "Warning: No citizens in collection, returning satisfaction of 0." << std::endl;
        return 0.0;
    }

    // Accumulate satisfaction scores
    for (shared_ptr<Citizen> temp : CitizenCollection) {
        double score = temp->getSatisfactionScore();
        // Check for invalid scores
        if (std::isnan(score)) {
            std::cout << "Warning: Encountered NaN score, ignoring it." << std::endl;
            continue; // Skip NaN scores
        }
        Satisfaction += score;
    }

    // Calculate and return average satisfaction
    return Satisfaction / count;
}

void Government::setPeopleCount(int count, int BusinessSatisfaction) {
    std::cout << "Max citizens: " << count << std::endl;
    std::cout << "Business Satisfaction: " << BusinessSatisfaction << std::endl;

    // Get the satisfaction value
    double satisfaction = getSatisfaction();
    std::cout << "Satisfaction: " << satisfaction << std::endl;

    // Calculate Combined Satisfaction
    double CombinedSatisfaction = (BusinessSatisfaction + satisfaction) / 2;
    
    // Check for division by zero when calculating ActualPopulation
    if (CombinedSatisfaction <= 0) { // Check for zero or negative values
        std::cout << "Warning: Combined Satisfaction is zero or negative, cannot calculate population." << std::endl;
        this->PopulationCount = 0; // Handle as appropriate
        return;
    }

    std::cout << "Combined Satisfaction: " << CombinedSatisfaction << std::endl;

    // Calculate Actual Population
    // Ensure proper casting to avoid overflow issues
    int ActualPopulation = static_cast<int>(count * CombinedSatisfaction/100);
    this->PopulationCount = ActualPopulation;
    this->CombinedSatisfaction = CombinedSatisfaction;

    std::cout << "Population Count calculated: " << PopulationCount << std::endl;

    // if(PopulationCount > CitizenCollection.size()){
    //     // create citizens
    //     int Difference = PopulationCount - CitizenCollection.size();
    //     for(int i=0; i<Difference; i++){
    //         addCitizen();
    //     } 
    // }
}

double Government::getCombinedSatisfaction(){
    return CombinedSatisfaction;
}


// void Government::setPeopleCount(int count, int BusinessSatisfaction) {
//     std::cout << "Max citizens: " << count << std::endl;
//     std::cout << "Business Satisfaction: " << BusinessSatisfaction << std::endl;

//     // Get the satisfaction value
//     double satisfaction = getSatisfaction();
//     std::cout << "Satisfaction: " << satisfaction << std::endl;

//     // Calculate Combined Satisfaction
//     double CombinedSatisfaction = (BusinessSatisfaction + satisfaction) / 2;
    
//     // Check for division by zero when calculating ActualPopulation
//     if (CombinedSatisfaction == 0) {
//         std::cout << "Warning: Combined Satisfaction is zero, cannot calculate population." << std::endl;
//         this->PopulationCount = 0; // Handle as appropriate
//         return;
//     }

//     std::cout << "Combined Satisfaction: " << CombinedSatisfaction << std::endl;

//     // Calculate Actual Population
//     int ActualPopulation = static_cast<int>(count / CombinedSatisfaction * 100);
//     this->PopulationCount = ActualPopulation;

//     std::cout << "Population Count calculated: " << PopulationCount << std::endl;
// }


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
