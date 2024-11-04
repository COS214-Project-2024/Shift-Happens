#ifndef HIGHTAX_H
#define HIGHTAX_H

#include "StandardTax.h"

/**
 * @class HighTax
 * @brief Represents the high tax state in a tax management system, applying elevated tax rates to citizens and businesses.
 *
 * This class inherits from `Tax` and defines a high tax rate state. It enforces a higher tax rate for both citizens and businesses:
 * - Citizens' tax rates are classified as "high" when above 35%.
 * - Businesses' tax rates are classified as "high" when above 27%.
 * If rates drop below these thresholds, the tax state may transition to a standard tax rate.
 */
class HighTax : public Tax {
	private:
		/**
		 * @brief Minimum threshold for a high tax rate for citizens, below which the tax state reverts to standard.
		 */
		int HighTLowCap = 35;

		/**
		 * @brief Minimum threshold for a high tax rate for businesses, below which the tax state reverts to standard.
		 */
		int HighTLowCapBusiness = 27;

	public:
		HighTax(std::shared_ptr<Government> government);
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
		 * @return A string representing the tax type, e.g., "high tax."
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

#endif // HIGHTAX_H
