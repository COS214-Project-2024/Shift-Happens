#ifndef POLICY_H
#define POLICY_H

#include <string>

/**
 * @class Policy
 * @brief Abstract base class representing government policies.
 * 
 * This class serves as the foundation for various policies that can be implemented by the government 
 * to address specific issues. Policies may relate to different situations, including:
 * - Overpopulation
 * - Underpopulation
 * - Unemployment
 * - Outdated public services
 * 
 * Each policy may involve specific actions and allocate budgets to different sectors, such as:
 * 1. **Overpopulation Command**: 
 *    - Aims to decrease population growth.
 *    - Affects multiple sectors, including education, police, and healthcare by allocating additional funding.
 * 2. **Boost Education**:
 *    - Receiver: Education
 *    - Increases the education budget to enhance educational services.
 * 3. **Boost Police**:
 *    - Receiver: Police
 *    - Increases the police budget to improve law enforcement services.
 * 4. **Boost Healthcare**:
 *    - Receiver: Healthcare
 *    - Increases the healthcare budget to improve health services.
 */

class Policy {
public:
    /**
     * @brief Executes the policy.
     * 
     * This method applies the policy's actions based on the available budget.
     * 
     * @param AvailableBudget The budget allocated for implementing the policy.
     */
    virtual void executePolicy(double AvailableBudget) = 0;

    /**
     * @brief Retrieves the type of the policy.
     * 
     * @return A string representing the specific type of policy.
     */
    virtual std::string getPolicyType() = 0;
};

#endif
