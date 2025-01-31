/*
 * test.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */


#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Zoo.h"
#include "Visitor.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <stdexcept>
using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the Animal classes. (XX points)
 */
void animalTests() {
    /*
     * (1) Create instances of Mammal and Bird classes with various attributes.
     *     Verify that their names, ages, and specific attributes (hasFur, canFly) are correctly set.
     *     Ensure that the makeSound method works correctly for both classes.
     *     (25 points)
     */
    // TODO
	Bird chakli("chakli",2,1);
	Mammal whale("whale",25,0);

	assertTrue(chakli.getAge()==2,"age is wrong");
	assertTrue(chakli.getCanFly()==1,"bird must be fly");
	assertTrue(chakli.getName()=="chakli","bird name is wrong");
	assertTrue(whale.getAge()==25,"age is wrong");
	assertTrue(whale.getHasFur()==0,"whale must have no fur");
	assertTrue(whale.getName()=="whale","whale name wrong");
	assertTrue(chakli.makeSound()=="Bro I am Bird","make sound wrong");
	assertTrue(whale.makeSound()=="Bro I am Mammal","make sound wrong");

}

/**
 * Tests for the Zoo class. (XX points)
 */
void zooTests() {
    /*
     * (1) Create a Zoo "Safari Park" and add various animals (Mammals and Birds).
     *     Verify the addition of animals and ensure that their attributes are correctly set.
     *     (20 points)
     *
     * (2) Test the countAnimals method to ensure it correctly counts each type of animal.
     *     (10 points)
     *
     * (3) Test the findOldestAnimal method to ensure it correctly identifies the oldest animal.
     *     (10 points)
     *
     * (4) Test the searchAnimalByName method to ensure it correctly finds animals by name.
     *     (10 points)
     *
     * (5) Test the findAnimalTypesByCount method to ensure it correctly identifies animal types
     *     with counts above a given threshold.
     *     (10 points)
     *
     * (6) Test the calculateAverageAge method to ensure it correctly calculates the average age of animals.
     *     (10 points)
     *
     * (7) Test the sortAnimalsByAge method to ensure it correctly sorts animals by age in descending order.
     *     (10 points)
     */
    // TODO

	Zoo safariPark("Safari Park");
	Bird* crow= new Bird("Crow",1,1);
	Bird* piegeon= new Bird("Piegeon",4,1);
	Mammal* lion=new Mammal("Lion",25,1);
	Mammal* tiger=new Mammal("Tiger",20,1);
	Mammal* dear=new Mammal("Dear",15,0);
	Bird* parrot= new Bird("Parrot",1,1);
	Mammal* giraf=new Mammal("Giraf",35,1);
	Mammal* hippo=new Mammal("Hippo",8,0);

	safariPark.addAnimal(std::unique_ptr<Animal>(crow));
	safariPark.addAnimal(std::unique_ptr<Animal>(piegeon));
	safariPark.addAnimal(std::unique_ptr<Animal>(lion));
	safariPark.addAnimal(std::unique_ptr<Animal>(tiger));
	safariPark.addAnimal(std::unique_ptr<Animal>(dear));
	safariPark.addAnimal(std::unique_ptr<Animal>(parrot));
	safariPark.addAnimal(std::unique_ptr<Animal>(giraf));
	safariPark.addAnimal(std::unique_ptr<Animal>(hippo));

	assertTrue(safariPark.searchAnimalByName("Lion")==1,"animal should be there");

	auto countAnimals=safariPark.countAnimals();

	for( auto iter = countAnimals.begin() ; iter != countAnimals.end() ; ++iter) {

		cout<<(*iter).first<<" "<<(*iter).second<<endl;
	}


	assertTrue(safariPark.findOldestAnimal()=="Giraf","oldest animal is wrong");

	auto thresholdAnimals=safariPark.findAnimalTypesByCount(4);

	for(auto iter = thresholdAnimals.begin(); iter != thresholdAnimals.end() ; ++iter) {

		assertTrue("Mammal"==(*iter),"threhold value wrong");
	}
	//cout<<safariPark.calculateAverageAge();�
	double expectedAvgAge=13.875;
	assertTrue(safariPark.calculateAverageAge()==expectedAvgAge,"avg age is wrong");


	auto sortedByAges=safariPark.sortAnimalsByAge();

	for(auto iter = sortedByAges.begin() ; iter != sortedByAges.end() ; ++iter) {

		cout<<(*iter)<<endl;
	}


	//std::unique_ptr<Animal>
}

/**
 * Tests for the Visitor class. (XX points)
 */
void visitorTests() {
    /*
     * (1) Create instances of Visitor class with various attributes.
     *     Verify that their names and ages are correctly set.
     *     Ensure that the zoo interaction (e.g., visiting animals) is correctly handled.
     *     (15 points)
     *
     *
     * (2) Test the visitZoo method to ensure visitors can visit multiple zoos.
     *     (5 points)
     *
     * (3) Test the getVisitedZoos method to ensure it correctly returns the list of visited zoos.
     *     (5 points)
     *
     * (4) Test the hasVisitedZoo method to ensure it correctly checks if a zoo has been visited.
     *     (5 points)
     */
    // TODO

	Visitor rutvik("rutvik",24);
	assertTrue(rutvik.getAge()==24,"age is wrong");
	assertTrue(rutvik.getName()=="rutvik","name is wrong");

	rutvik.visitZoo("Safari Park");
	rutvik.visitZoo("Madagascar");

	assertTrue(rutvik.getVisitedZoos().size()==2,"vistor should visit multile zoo");

	assertTrue(rutvik.hasVisitedZoo("Madagascar")==1,"visited zoo wrong");

}

/**
 * Comprehensive tests involving multiple relationships. (XX points)
 */
void comprehensiveTests() {
    /*
     * (1) Create a zoo system where visitors can visit multiple zoos and interact with various animals.
     *     Verify the complex relationships and interactions among visitors, zoos, and animals.
     *     Use a mix of algorithms (like searching and sorting) to ensure complex interactions are handled correctly.
     *     (20 points)
     */
    // TODO
}

void allTests() {
    animalTests();
    zooTests();
    visitorTests();
    comprehensiveTests();
}


