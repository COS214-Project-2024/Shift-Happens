#ifndef UNDERPOPULATED_H
#define UNDERPOPULATED_H

#include "Population.h"
#include "Normal.h"

/**
 * @class UnderPopulated
 * @brief Concrete state representing an underpopulated condition within a population.
 *
 * The `UnderPopulated` class inherits from the `Population` base class and defines behavior
 * specific to a state where the population is significantly below acceptable limits. In this 
 * state, the population count is low, potentially leading to negative consequences for the 
 * community, such as labor shortages and reduced economic activity. This class manages the 
 * transitions to and from the underpopulated state based on changes in the population count.
 */
class UnderPopulated : public Population {
	private:
		/**
		 * @brief The upper cap for the underpopulated state.
		 *
		 * If the population count exceeds this threshold, the state will transition
		 * to a `Normal` state. The cap is set at 400 citizens for this implementation.
		 */
		int PopUnderHighCap = 400;

	public:
		/**
		 * @brief Increases the population count, potentially impacting state.
		 * @param increase The number of citizens to add to the population.
		 *
		 * This method adjusts the population count upwards and checks if the new
		 * count exceeds the defined limits, possibly transitioning to the `Normal` state.
		 */
		void increasePopulation(int increase) override;

		/**
		 * @brief Decreases the population count, potentially impacting state.
		 * @param decrease The number of citizens to remove from the population.
		 *
		 * This method reduces the population count and checks if the resulting count
		 * falls below the threshold to maintain the `UnderPopulated` state.
		 */
		void decreasePopulation(int decrease) override;

		/**
		 * @brief Returns the type of the current population state.
		 * @return A string indicating the population state as "Underpopulated".
		 *
		 * This method provides a human-readable description of the current population state
		 * for diagnostic or user interface purposes.
		 */
		std::string getType() override;
};

#endif // UNDERPOPULATED_H
