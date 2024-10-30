#ifndef TAX_H
#define TAX_H

#include "../Government/Government.h"
#include <iostream>

/**
 * @class Tax
 * @brief Abstract base class defining the structure for different tax states in the tax management system.
 *
 * The `Tax` class establishes the interface for tax rate adjustments and provides basic functionality 
 * for retrieving current tax rates. Derived classes, such as `LowTax`, `StandardTax`, and `HighTax`, 
 * implement specific tax behavior based on rate thresholds.
 */
class Tax {
	private:
		// Private members, if any, can be documented here as needed.

	protected:
		/**
		 * @brief Pointer to the Government instance, allowing access to government functions and data.
		 */
		std::shared_ptr<Government> government;

		/**
		 * @brief Holds the current tax rate for individuals.
		 */
		double RunningRate;

		/**
		 * @brief Holds the current tax rate for businesses.
		 */
		double RunningRateBusiness;

	public:
		/**
		 * @brief Increases the current tax rate for citizens. Must be implemented by derived classes.
		 * @param increase The amount by which to increase the citizen tax rate.
		 */
		virtual void higher(double increase) = 0;

		/**
		 * @brief Decreases the current tax rate for citizens. Must be implemented by derived classes.
		 * @param decrease The amount by which to decrease the citizen tax rate.
		 */
		virtual void lower(double decrease) = 0;

		/**
		 * @brief Retrieves the type of tax rate as a string, indicating the current tax state.
		 * @return A string representing the tax type, such as "low tax" or "standard tax."
		 */
		virtual std::string getType() = 0;

		/**
		 * @brief Retrieves the current tax rate for citizens.
		 * @return The current citizen tax rate as a double.
		 */
		double getRate();

		/**
		 * @brief Increases the current tax rate for businesses. Must be implemented by derived classes.
		 * @param increase The amount by which to increase the business tax rate.
		 */
		virtual void higherBusiness(double increase) = 0;

		/**
		 * @brief Decreases the current tax rate for businesses. Must be implemented by derived classes.
		 * @param decrease The amount by which to decrease the business tax rate.
		 */
		virtual void lowerBusiness(double decrease) = 0;

		/**
		 * @brief Retrieves the current tax rate for businesses.
		 * @return The current business tax rate as a double.
		 */
		double getBusinessRate();
};

#endif // TAX_H
