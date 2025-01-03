#include <algorithm>
#include "Statistics.h"

Statistics::Statistics() : map(Map::getInstance()) {
    
    this->money = 1000000;
    this->income = 10;
    this->population = 0;
    this->maxPopulation = 0;
    this->employment = 0;
    this->satisfaction = 0;
    this->waterSupply = 0;
    this->powerSupply = 0;
    this->sewageCapacity = 0;
    this->wasteCapacity = 0;

    this->waterConsumption = 0;
    this->powerConsumption = 0;
    this->sewageProduction = 0;
    this->wasteProduction = 0;

    this->uncollectedBusinessTax = 0;
    this->uncollectedBusinessTax = 0;


    government = make_shared<Government>();
    
    government->setTaxState(make_shared<StandardTax>(government));
    government->setBusinessTaxState(make_shared<StandardTax>(government));
    government->setPersonalTaxRate(government->getTax()->getRate());
    government->setBusinessTaxRate(government->getBusinessTax()->getBusinessRate());
}

void Statistics::updateStats() {

    money += income;
    income = map.getIncome();
    
    //satisfaction = (map.getAverageSatisfactionScore() + government->getSatisfaction())/2;
    waterSupply = map.getTotalWaterSupply();
    powerSupply = map.getTotalElectricitySupply();
    sewageCapacity = map.getTotalSewageCapacity();
    wasteCapacity = map.getTotalWasteCapacity();

    waterConsumption = map.getTotalWaterUsage();
    powerConsumption = map.getTotalElectricityDemand();
    sewageProduction = map.getTotalSewageProduction();
    wasteProduction = map.getTotalWasteProduction();

    employment = map.getTotalNumberOfJobs();
    maxPopulation = map.getTotalPopulationCapacity();
    government->setPeopleCount(maxPopulation, map.getAverageSatisfactionScore());
    population = government->getPeopleCount();
    satisfaction = government->getCombinedSatisfaction();
    uncollectedBusinessTax += government->CollectBusinessTax(map.getTotalNumBuildings());
    uncollectedPersonalTax += government->CollectPersonalTax();
}


int Statistics::getMoney() {
    return money;
}

int Statistics::getIncome() {
    return income;
}

int Statistics::getPopulation() {
    return population;
}

int Statistics::getMaxPopulation() {
    return maxPopulation;
}

int Statistics::getEmployment() {
    return employment;
}

int Statistics::getSatisfaction() {
    return satisfaction;
}

int Statistics::getWaterSupply() {
    return waterSupply;
}

int Statistics::getPowerSupply() {
    return powerSupply;
}

int Statistics::getSewageCapacity() {
    return sewageCapacity;
}

int Statistics::getWasteCapacity() {
    return wasteCapacity;
}

int Statistics::getWaterConsumption() {
    return waterConsumption;
}

int Statistics::getPowerConsumption() {
    return powerConsumption;
}

int Statistics::getSewageProduction() {
    return sewageProduction;
}

int Statistics::getWasteProduction() {
    return wasteProduction;
}

void Statistics::setMoney(int m) {
    money = m;
}

void Statistics::setIncome(int i) {
    income = i;
}

void Statistics::setPopulation(int p) {
    population = p;
}

void Statistics::setMaxPopulation(int mp) {
    maxPopulation = mp;
}

void Statistics::setEmployment(int e) {
    employment = e;
}

void Statistics::setSatisfaction(int s) {
    satisfaction = s;
}

void Statistics::setWaterSupply(int ws) {
    waterSupply = ws;
}

void Statistics::setPowerSupply(int ps) {
    powerSupply = ps;
}

void Statistics::setSewageCapacity(int sc) {
    sewageCapacity = sc;
}

void Statistics::setWasteCapacity(int wc) {
    wasteCapacity = wc;
}

void Statistics::setWaterConsumption(int wc) {
    waterConsumption = wc;
}

void Statistics::setPowerConsumption(int pc) {
    powerConsumption = pc;
}

void Statistics::setSewageProduction(int sp) {
    sewageProduction = sp;
}

void Statistics::setWasteProduction(int wp) {
    wasteProduction = wp;
}


void Statistics::collectBusinessTax() {
    money += uncollectedBusinessTax;
    uncollectedBusinessTax = 0;
}


void Statistics::collectPersonalTax() {
    money += uncollectedPersonalTax;
    uncollectedPersonalTax = 0;
}

void Statistics::changePersonalTax(double amount, std::string type) {
    cout << "Entered tax change" << endl;
    if(type == "increase"){
        government->setPersonalTaxHigher(amount);
    } else if(type == "decrease"){
        government->setPersonalTaxLower(amount);
    }
    cout << "Exited statistics" << endl;
}

void Statistics::changeBusinessTax(double amount, std::string type) {
    if(type == "increase"){
        government->setBusinessTaxHigher(amount);
    } else if(type == "decrease"){
        government->setBusinessTaxLower(amount);
    }
}

void Statistics::changeBudget(string type, string change) {
    if(type == "police"){
        if(change == "increase"){
            government->getPolice()->DelegateFunds("increase");
        } else if(change == "decrease"){
            government->getPolice()->DelegateFunds("decrease");
        }
    } else if(type == "education"){
        if(change == "increase"){
            government->getEducation()->DelegateFunds("increase");
        } else if(change == "decrease"){
            government->getEducation()->DelegateFunds("decrease");
        }
    } else if(type == "healthcare"){
        if(change == "increase"){
            government->getHealthCare()->DelegateFunds("increase");
        } else if(change == "decrease"){
            government->getHealthCare()->DelegateFunds("decrease");
        }
    }
}

string Statistics::implementPolicy(string policy) {

    if (money < 1000)
    {
        return "Insufficient funds";
    }
    
    if (policy == "Boost Education Policy ($1000)") {
        government->addExecutePolicy("Boost Education Policy");
        return "Boost Education has been implemented.";
    }else if (policy == "Boost Healthcare Policy ($1000)") {
        government->addExecutePolicy("Boost Healthcare Policy");
        return "Boost Healthcare has been implemented.";
    }else if (policy == "Boost Police Policy ($1000)") {
        government->addExecutePolicy("Boost Police Policy");
        return "Boost Police has been implemented.";
    } else {
        string error = "Statistics::implementPolicy() invalid policy: " + policy;
        throw error;
    }
    
}

vector<string> Statistics::getCurrentPolicies(){
    vector<string> CurrentPolicies;
    for (const auto& policy : government->getCurrentPolicies()) {
        CurrentPolicies.push_back(policy->getPolicyType());
    }

    return CurrentPolicies;
    
}

shared_ptr<Government> Statistics::getGovernment(){
    return this->government;
}

int Statistics::getUncollectedTax(string type){
    if(type == "business"){
        return uncollectedBusinessTax;
    } else if(type == "personal"){
        return uncollectedPersonalTax;
    }
    else{
        throw "Statistics::getUncollectedTax() invalid type";
    }
    return -1;
}


vector<vector<string>> Statistics::getImplementedPolicies(){
    vector<vector<string>> implementedPolicies;
    int i = 1;
    if (government->getCurrentPolicies().empty())
    {
        return implementedPolicies;
    }
    
    for (const auto& policy : government->getCurrentPolicies()) {
        vector<string> temp;
        temp.push_back(to_string(i) + ". " + policy->getPolicyType());
        temp.push_back("Cost: " + to_string(policy->getCostOfPolicy()));
        implementedPolicies.push_back(temp);
    }
    return implementedPolicies;

}

vector<string> Statistics::getAvailablePolicies(){
    vector<string> availablePolicies;
    if (government->getAvailablePolicies().empty())
    {
        return availablePolicies;
    }
    
    for (const auto& policy : government->getAvailablePolicies()) {
        int cost = policy->getCostOfPolicy();
        string temp = policy->getPolicyType() + " ($" + to_string(cost) + ")";
        availablePolicies.push_back(temp);
    }
    return availablePolicies;
}

//transportation functions:
void Statistics::setStrategy(shared_ptr<TransportationStrategy> strat) {
    strategy = move(strat);
}

// Gets the cost of traveling the specified distance using the selected strategy
double Statistics::getCost(int distance) {
    if (strategy) {
        return strategy->calculateCost(distance);
    } else {
        cerr << "Error: No transportation strategy is set." << endl;
        return 0.0;
    }
}

// Gets the duration of traveling the specified distance using the selected strategy
double Statistics::getDuration(int distance) {
    if (strategy) {
        return strategy->calculateDuration(distance);
    } else {
        cerr << "Error: No transportation strategy is set." << endl;
        return 0.0;
    }
}

void Statistics::displayOption(int distance) {
    if (strategy) {
        cout << "Transport Mode: " << strategy->getType() << endl;
        cout << "Estimated Cost: $" << getCost(distance) << " USD" << endl;
        cout << "Estimated Duration: " << getDuration(distance) << " minutes" << endl;
    } else {
        cout << "No transportation strategy set." << endl;
    }
}
