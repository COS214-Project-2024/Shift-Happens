#ifndef STANDARDTAX_H
#define STANDARDTAX_H

#include "Tax.h"
#include "HighTax.h"
#include "LowTax.h"
#include "../Government/Government.h"

/**
 * @class StandardTax
 * @brief Represents the standard tax state in the tax management system, with mid-range thresholds for both citizens and businesses.
 *
 * This class inherits from `Tax` and defines the standard tax rate state, applying mid-range tax rates. 
 * - For citizens, tax rates are classified as "standard" when they are between 20% and 35%.
 * - For businesses, tax rates are "standard" when they are between 7% and 27%.
 * Rates that move above or below these thresholds may trigger transitions to a higher or lower tax state.
 */
class StandardTax : public Tax {
	private:
		/**
		 * @brief Upper threshold for the standard tax rate for citizens. If the rate exceeds this cap, it may trigger a transition to a high tax state.
		 */
		int StandardTHighCap = 35;

		/**
		 * @brief Lower threshold for the standard tax rate for citizens. If the rate drops below this cap, it may trigger a transition to a low tax state.
		 */
		int StandardTLowCap = 20;

		/**
		 * @brief Upper threshold for the standard tax rate for businesses. If the rate exceeds this cap, it may trigger a transition to a high tax state.
		 */
		int StandardTHighCapBusiness = 27;

		/**
		 * @brief Lower threshold for the standard tax rate for businesses. If the rate drops below this cap, it may trigger a transition to a low tax state.
		 */
		int StandardTLowCapBusiness = 7;

	public:
		StandardTax(std::shared_ptr<Government> government);
		/**
		 * @brief Increases the current tax rate for citizens.
		 * @param increase The amount by which the citizens' tax rate is raised.
		 */
		void higher(double increase);

		/**
		 * @brief Decreases the current tax rate for citizens.
		 * @param decrease The amount by which the citizens' tax rate is reduced.
		 */
		void lower(double decrease);

		/**
		 * @brief Retrieves the type of tax rate.
		 * @return A string representing the tax type, e.g., "standard tax."
		 */
		std::string getType();

		/**
		 * @brief Increases the current tax rate for businesses.
		 * @param increase The amount by which the business tax rate is raised.
		 */
		void higherBusiness(double increase);

		/**
		 * @brief Decreases the current tax rate for businesses.
		 * @param decrease The amount by which the business tax rate is reduced.
		 */
		void lowerBusiness(double decrease);
};

#endif // STANDARDTAX_H
