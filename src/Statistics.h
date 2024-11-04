#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "map/Map.h"
#include "map/Transportation/TransportationStrategy.h"
#include "Government/Government.h"
#include "Government/StandardTax.h"
#include "Government/LowTax.h"
#include "Government/HighTax.h"

using namespace std;

/**
 * @class Statistics
 * @brief Manages city statistics including population, resources, government, and transportation strategies.
 *
 * This class provides functions to update and retrieve various statistics related
 * to the city, such as population, resource consumption, satisfaction, and
 * tax collection. It also enables interactions with the government and transportation.
 */
class Statistics
{
private:
	/** @brief Reference to the Map object representing the city layout and infrastructure. */
	Map &map;

	// Financial statistics
	int money;	///< City's total money.
	int income; ///< City's income.

	// Population statistics
	int population;	   ///< Current city population.
	int maxPopulation; ///< Maximum possible population.

	// Employment and satisfaction
	int employment;	  ///< Employment rate.
	int satisfaction; ///< Citizen satisfaction level.

	// Resource capacities
	int waterSupply;	///< Total water supply capacity.
	int powerSupply;	///< Total power supply capacity.
	int sewageCapacity; ///< Total sewage capacity.
	int wasteCapacity;	///< Total waste capacity.

	// Resource consumption
	int waterConsumption; ///< Current water consumption.
	int powerConsumption; ///< Current power consumption.
	int sewageProduction; ///< Current sewage production.
	int wasteProduction;  ///< Current waste production.

	// Tax collection
	int uncollectedBusinessTax; ///< Business taxes pending collection.
	int uncollectedPersonalTax; ///< Personal taxes pending collection.

	/** @brief Pointer to the government instance responsible for policy and taxation. */
	std::shared_ptr<Government> government;

	/** @brief Pointer to the strategy for managing transportation within the city. */
	shared_ptr<TransportationStrategy> strategy;

public:
	/** @brief Constructor initializes city statistics with default values. */
	Statistics();

	/** @brief Updates all city statistics. */
	void updateStats();

	// Getters
	int getMoney();			   ///< Retrieves current money.
	int getIncome();		   ///< Retrieves current income.
	int getPopulation();	   ///< Retrieves current population.
	int getMaxPopulation();	   ///< Retrieves maximum possible population.
	int getEmployment();	   ///< Retrieves employment rate.
	int getSatisfaction();	   ///< Retrieves citizen satisfaction level.
	int getWaterSupply();	   ///< Retrieves water supply capacity.
	int getPowerSupply();	   ///< Retrieves power supply capacity.
	int getSewageCapacity();   ///< Retrieves sewage capacity.
	int getWasteCapacity();	   ///< Retrieves waste capacity.
	int getWaterConsumption(); ///< Retrieves current water consumption.
	int getPowerConsumption(); ///< Retrieves current power consumption.
	int getSewageProduction(); ///< Retrieves current sewage production.
	int getWasteProduction();  ///< Retrieves current waste production.

	// Setters
	void setMoney(int m);			  ///< Sets the city's money.
	void setIncome(int i);			  ///< Sets the city's income.
	void setPopulation(int p);		  ///< Sets the city's population.
	void setMaxPopulation(int mp);	  ///< Sets the maximum population.
	void setEmployment(int e);		  ///< Sets the employment rate.
	void setSatisfaction(int s);	  ///< Sets citizen satisfaction.
	void setWaterSupply(int ws);	  ///< Sets water supply capacity.
	void setPowerSupply(int ps);	  ///< Sets power supply capacity.
	void setSewageCapacity(int sc);	  ///< Sets sewage capacity.
	void setWasteCapacity(int wc);	  ///< Sets waste capacity.
	void setWaterConsumption(int wc); ///< Sets water consumption.
	void setPowerConsumption(int pc); ///< Sets power consumption.
	void setSewageProduction(int sp); ///< Sets sewage production.
	void setWasteProduction(int wp);  ///< Sets waste production.

	// Government functions
	/**
	 * @brief Modifies the business tax rate based on a specified type.
	 * @param rate The new tax rate.
	 * @param type Type of tax (e.g., "standard", "low", "high").
	 */
	void changeBusinessTax(double rate, string type);

	/**
	 * @brief Modifies the personal tax rate based on a specified type.
	 * @param rate The new tax rate.
	 * @param type Type of tax (e.g., "standard", "low", "high").
	 */
	void changePersonalTax(double rate, string type);

	/** @brief Collects outstanding business taxes. */
	void collectBusinessTax();

	/** @brief Collects outstanding personal taxes. */
	void collectPersonalTax();

	/** @brief Retrieves the current government instance. */
	shared_ptr<Government> getGovernment();

	/**
	 * @brief Implements a policy and adjusts city parameters accordingly.
	 * @param policy The policy to implement.
	 * @return A string describing the policy's impact.
	 */
	string implementPolicy(string policy);

	/** @brief Retrieves a list of currently implemented policies. */
	vector<string> getCurrentPolicies();

	/**
	 * @brief Adjusts the city budget based on specified type and change.
	 * @param type The budget type (e.g., "education", "healthcare").
	 * @param change The change amount.
	 */
	void changeBudget(string type, string change);

	/**
	 * @brief Retrieves the amount of uncollected tax based on the type.
	 * @param type The type of tax ("business" or "personal").
	 * @return The uncollected tax amount.
	 */
	int getUncollectedTax(string type);

	/** @brief Retrieves a matrix of all implemented policies with details. */
	vector<vector<string>> getImplementedPolicies();

	/** @brief Retrieves a list of available policies that can be implemented. */
	vector<string> getAvailablePolicies();

	// Transportation functions
	/**
	 * @brief Sets the transportation strategy for calculating travel.
	 * @param strat The transportation strategy to set.
	 */
	void setStrategy(shared_ptr<TransportationStrategy> strat);

	/**
	 * @brief Calculates the travel cost based on distance.
	 * @param distance The travel distance.
	 * @return The travel cost.
	 */
	double getCost(int distance);

	/**
	 * @brief Calculates the travel duration based on distance.
	 * @param distance The travel distance.
	 * @return The travel duration.
	 */
	double getDuration(int distance);

	/**
	 * @brief Displays travel options based on the distance.
	 * @param distance The travel distance.
	 */
	void displayOption(int distance);
};

#endif // STATISTICS_H
