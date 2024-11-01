#ifndef POPULATION_H
#define POPULATION_H

#include "../Government/Economy.h"
#include <iostream>	

/**
 * @class Population
 * @brief Abstract base class representing various population states within an economy.
 *
 * The `Population` class defines the foundational structure for population states, including
 * overpopulation, underpopulation, and normal levels. Overpopulation and underpopulation represent
 * states with potentially negative impacts on citizen well-being, while a normal population is balanced.
 * The class maintains a population count, which determines the current state of the population and
 * can trigger state-dependent responses in associated economic models.
 */

class Economy;
class Population {
	protected:
		/**
		 * @brief Stores the current count of citizens.
		 *
		 * This variable tracks the population size and is utilized by derived classes to
		 * determine whether the population is in an overpopulated, underpopulated, or normal state.
		 */
		int PopulationCount;

		/**
		 * @brief Pointer to the associated `Economy` object.
		 *
		 * The `economy` pointer allows the population state to interact with and update the economy,
		 * enabling state changes in population to reflect within the broader economic context.
		 */
		std::shared_ptr<Economy> economy;
	
	public:
		/**
		 * @brief Increases the population count, potentially triggering state transitions.
		 * @param increase The amount to add to the population count.
		 *
		 * This method adjusts the population size upwards and may lead to a state transition
		 * (e.g., normal to overpopulated) depending on thresholds set in derived classes.
		 */
		virtual void increasePopulation(int increase) = 0;

		/**
		 * @brief Decreases the population count, potentially triggering state transitions.
		 * @param decrease The amount to subtract from the population count.
		 *
		 * This method reduces the population size and can lead to a state transition
		 * (e.g., normal to underpopulated) depending on derived class logic.
		 */
		virtual void decreasePopulation(int decrease) = 0;

		/**
		 * @brief Returns a string describing the current population state.
		 * @return A string indicating the population state, such as "Overpopulated" or "Underpopulated".
		 *
		 * Provides a human-readable representation of the population state for diagnostic or user interface purposes.
		 */
		virtual std::string getType() = 0;
		int getPopulationCount();
		void setEconomy(std::shared_ptr<Economy> PassedEconomy);
};

#endif // POPULATION_H
