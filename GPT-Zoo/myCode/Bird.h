/*
 * Bird.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef BIRD_H_
#define BIRD_H_


#include "Animal.h"

/**
 * Represents a bird in the zoo.
 */
class Bird : public Animal {
protected:
    bool canFly;

public:
    Bird(std::string name, int age, bool canFly);

    virtual std::string makeSound() const override;

    bool getCanFly() const;
};

#endif /* BIRD_H_ */
