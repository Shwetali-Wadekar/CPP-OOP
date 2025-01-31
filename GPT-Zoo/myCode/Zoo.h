/*
 * Zoo.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef ZOO_H_
#define ZOO_H_


#include <vector>
#include <memory>
#include <map>
#include <set>
#include<string>
class Animal;

/**
 * Represents a zoo which contains various animals.
 */
class Zoo {
private:
    std::string name;
    std::vector<std::unique_ptr<Animal>> animals;
    std::map<std::string, int> animalCount; // animal type to count
    std::set<std::string> animalTypes; // distinct types of animals

public:
    Zoo(std::string name);

    void addAnimal(std::unique_ptr<Animal> animal);
    std::string getName() const;
    std::vector<Animal*> getAnimals() const;

    /**
     * Count the number of each type of animal in the zoo.
     * Use an internal map to store the counts and return it.
     */
    std::map<std::string, int> countAnimals() ;

    /**
     * Find the oldest animal in the zoo.
     * Return the name of the oldest animal.
     */
    std::string findOldestAnimal() const;

    /**
     * Perform a search to find if there is an animal
     * with the given name in the zoo. Return true if found, false otherwise.
     */
    bool searchAnimalByName(const std::string& name) const;

    /**
     * Find the animal types that have more than a given threshold count.
     * Return a set of such animal types.
     */
    std::set<std::string> findAnimalTypesByCount(int threshold) const;

    /**
     * Calculate the average age of animals in the zoo.
     * Return the average age.
     */
    double calculateAverageAge() const;

    /**
     * Sort animals by age in descending order.
     * Return a sorted vector of animal names.
     */
    std::vector<std::string> sortAnimalsByAge() const;
};
#endif /* ZOO_H_ */
