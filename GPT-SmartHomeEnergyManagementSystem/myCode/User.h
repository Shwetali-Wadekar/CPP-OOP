/*
 * User.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef USER_H_
#define USER_H_


#include <string>
#include <vector>
#include <memory>


class Appliance;
/**
 * Represents a user of the smart home system.
 */
class User {
private:
    std::string id; // Unique identifier for the user
    std::string name; // Name of the user
    std::vector<std::shared_ptr<Appliance>> appliances; // List of appliances associated with the user

public:
    /**
     * Constructor for User class.
     * @param id Unique identifier for the user.
     * @param name Name of the user.
     */
    User(std::string id, std::string name);

    /**
     * Gets the unique identifier for the user.
     * @return User ID as a string.
     */
    std::string getId() const;

    /**
     * Gets the name of the user.
     * @return User name as a string.
     */
    std::string getName() const;

    /**
     * Adds an appliance to the user's list.
     * @param appliance A shared pointer to the appliance to be added.
     */
    void addAppliance(std::shared_ptr<Appliance> appliance);

    /**
     * Retrieves all appliances associated with the user.
     * @return A vector of shared pointers to appliances.
     */
    std::vector<std::shared_ptr<Appliance>> getAppliances() const;

    /**
     * Displays user details and their appliances.
     * @return A string containing user and appliance details.
     */
    std::string displayDetails() const;
};

#endif /* USER_H_ */
