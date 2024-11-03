
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
}

void Statistics::updateStats() {

    money += income;
    income = map.getIncome();
    
    satisfaction = map.getAverageSatisfactionScore();
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
    throw "Statistics::collectBusinessTax() not implemented";
}


void Statistics::collectPersonalTax() {
    throw "Statistics::collectPersonalTax() not implemented";
}

void Statistics::changePersonalTax(double amount, std::string type) {
    throw "Statistics::changePersonalTax() not implemented";
}

void Statistics::changeBusinessTax(double amount, std::string type) {
    throw "Statistics::changeBusinessTax() not implemented";
}

void Statistics::changeBudget(string type, string change) {
    throw "Statistics::changeBudget() not implemented";
}

void Statistics::implementPolicy(){
    throw "Statistics::implementPolicy() not implemented";
}

vector<string> Statistics::getCurrentPolicies(){
    throw "Statistics::getCurrentPolicies() not implemented";
}




