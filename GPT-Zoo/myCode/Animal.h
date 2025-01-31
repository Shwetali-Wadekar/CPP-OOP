/*
 * Animal.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_


#include <string>

/**
 * Represents a generic animal in the zoo.
 */
class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(std::string name, int age);

    virtual ~Animal() = default;

    virtual std::string makeSound() const = 0;

    std::string getName() const;
    int getAge() const;
};

#endif /* ANIMAL_H_ */
