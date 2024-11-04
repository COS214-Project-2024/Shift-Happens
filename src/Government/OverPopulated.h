#ifndef OVERPOPULATED_H
#define OVERPOPULATED_H

#include "Population.h"
#include "Normal.h"

/**
 * @class OverPopulated
 * @brief Concrete state representing an overpopulated condition within a population.
 *
 * The `OverPopulated` class inherits from the `Population` base class and defines behavior
 * specific to a state where the population exceeds acceptable limits. In this state, the 
 * population count is significantly high, potentially leading to negative consequences
 * for citizens, such as resource depletion and diminished quality of life. This class 
 * manages the transitions to and from the overpopulated state based on population changes.
 */
class OverPopulated : public Population {
	private:
		/**
		 * @brief The lower cap for the overpopulated state.
		 *
		 * If the population count falls below this threshold, the state will transition
		 * to a `Normal` state. The cap is set at 2000 citizens for this implementation.
		 */
		int PopOverLowCap = 2000;

	public:
		/**
		 * @brief Increases the population count, potentially impacting state.
		 * @param increase The number of citizens to add to the population.
		 *
		 * This method adjusts the population count upwards and checks if the new
		 * count exceeds the defined limits, possibly maintaining the overpopulated state.
		 */
		void increasePopulation(int increase) override;

		/**
		 * @brief Decreases the population count, potentially impacting state.
		 * @param decrease The number of citizens to remove from the population.
		 *
		 * This method reduces the population count and checks if the resulting count
		 * falls below the threshold to transition to the `Normal` state.
		 */
		void decreasePopulation(int decrease) override;

		/**
		 * @brief Returns the type of the current population state.
		 * @return A string indicating the population state as "Overpopulated".
		 *
		 * This method provides a human-readable description of the current population state
		 * for diagnostic or user interface purposes.
		 */
		std::string getType() override;
};

#endif // OVERPOPULATED_H
