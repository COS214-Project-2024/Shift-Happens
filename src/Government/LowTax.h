#ifndef LOWTAX_H
#define LOWTAX_H

#include "StandardTax.h"

/**
 * @class LowTax
 * @brief Represents the low tax state in a tax management system, applying reduced tax rates to citizens and businesses.
 *
 * This class inherits from `Tax` and defines a low tax rate state. It maintains lower tax thresholds for both citizens and businesses:
 * - Citizens' tax rates are classified as "low" when they remain below 20%.
 * - Businesses' tax rates are classified as "low" when they remain below 7%.
 * If tax rates exceed these caps, the tax state may transition to a higher tax rate.
 */
class LowTax : public Tax {
	private:
		/**
		 * @brief Maximum threshold for a low tax rate for citizens, above which the tax state may transition to a standard or high rate.
		 */
		int LowTHighCap = 20;

		/**
		 * @brief Maximum threshold for a low tax rate for businesses, above which the tax state may transition to a standard or high rate.
		 */
		int LowTHighCapBusiness = 7;

	public:
		LowTax();
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
		 * @return A string representing the tax type, e.g., "low tax."
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

#endif // LOWTAX_H
