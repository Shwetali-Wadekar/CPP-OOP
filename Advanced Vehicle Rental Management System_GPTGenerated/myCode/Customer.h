#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>

/**
 * Represents a customer in the vehicle rental system.
 */
class Customer {
private:
    std::string name;
    std::string customerID;

public:
    /**
     * Initializes a new customer with the given name and customer ID.
     *
     * @param name the customer's name
     * @param customerID the customer's ID
     */
    Customer(const std::string& name, const std::string& customerID);

    /**
     * Returns the customer's name.
     *
     * @return the customer's name
     */
    std::string getName() const;

    /**
     * Returns the customer's ID.
     *
     * @return the customer's ID
     */
    std::string getCustomerID() const;
};

#endif /* CUSTOMER_H_ */
