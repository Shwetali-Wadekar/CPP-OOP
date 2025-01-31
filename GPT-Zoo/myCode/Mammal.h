/*
 * Mammal.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_


#include "Animal.h"

/**
 * Represents a mammal in the zoo.
 */
class Mammal : public Animal {
protected:
    bool hasFur;

public:
    Mammal(std::string name, int age, bool hasFur);

    virtual std::string makeSound() const override;

    bool getHasFur() const;
};


#endif /* MAMMAL_H_ */
