#ifndef NORMAL_H
#define NORMAL_H

#include "Population.h"
#include "OverPopulated.h"
#include "UnderPopulated.h"

/**
 * @class Normal
 * @brief Concrete state representing a normal population condition.
 *
 * The `Normal` class inherits from the `Population` base class and defines behavior 
 * specific to a state where the population is at an acceptable level. This state 
 * signifies a balanced population, which is vital for maintaining economic stability 
 * and community well-being. The class manages population count changes and 
 * transitions to `OverPopulated` or `UnderPopulated` states when thresholds are crossed.
 */
class Normal : public Population {
	private:
		/**
		 * @brief The upper cap for the normal population state.
		 *
		 * If the population count exceeds this threshold, the state transitions 
		 * to an `OverPopulated` state. The cap is set at 2000 citizens for this 
		 * implementation.
		 */
		int PopNormalHighCap = 2000;

		/**
		 * @brief The lower cap for the normal population state.
		 *
		 * If the population count falls below this threshold, the state transitions 
		 * to an `UnderPopulated` state. The cap is set at 400 citizens for this 
		 * implementation.
		 */
		int PopNormalLowCap = 400;

	public:
		/**
		 * @brief Increases the population count, potentially impacting state.
		 * @param increase The number of citizens to add to the population.
		 *
		 * This method adjusts the population count upwards and checks if the new
		 * count exceeds the defined limits, possibly transitioning to the 
		 * `OverPopulated` state.
		 */
		void increasePopulation(int increase) override;

		/**
		 * @brief Decreases the population count, potentially impacting state.
		 * @param decrease The number of citizens to remove from the population.
		 *
		 * This method reduces the population count and checks if the resulting count 
		 * falls below the threshold to transition to the `UnderPopulated` state.
		 */
		void decreasePopulation(int decrease) override;

		/**
		 * @brief Returns the type of the current population state.
		 * @return A string indicating the population state as "Normal".
		 *
		 * This method provides a human-readable description of the current population 
		 * state for diagnostic or user interface purposes.
		 */
		std::string getType() override;
};

#endif // NORMAL_H
