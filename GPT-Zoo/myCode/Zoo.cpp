/*
 * Zoo.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#include "Zoo.h"
#include "Animal.h"
#include<algorithm>
//    std::vector<std::unique_ptr<Animal>> animals;
//    std::map<std::string, int> animalCount; // animal type to count
//    std::set<std::string> animalTypes; // distinct types of animals
Zoo::Zoo(std::string name) : name(name)
{
}

void Zoo::addAnimal(std::unique_ptr<Animal> animal)
{
	animals.push_back(move(animal));
}

std::string Zoo::getName() const
{
	return name;
}

std::vector<Animal*> Zoo::getAnimals() const
{
	std::vector<Animal*> allAnimals;
	for(auto iter = animals.begin() ; iter != animals.end() ; ++iter) {
		allAnimals.push_back((*iter).get());
	}
	return allAnimals;
}

std::map<std::string, int> Zoo::countAnimals()
{
	std::string bird="Bird";
	std::string mammal="Mammal";
	int birdCount=0;
	int mammalCount=0;
	for(auto iter = animals.begin() ; iter != animals.end() ; ++iter) {
		if((*iter)->makeSound()=="Bro I am Bird") {
			birdCount++;
		}else {
			mammalCount++;
		}
	}

	animalCount[bird]=birdCount;
	animalCount[mammal]=mammalCount;

	return animalCount;

}

std::string Zoo::findOldestAnimal() const
{
	int age=0;
	auto oldestAnimal=animals.begin();

	for(auto iter = animals.begin() ; iter != animals.end() ; ++iter) {
		if((*iter)->getAge()>age) {
			age=(*iter)->getAge();
			oldestAnimal=iter;
		}
	}

	return (*oldestAnimal)->getName();
}

bool Zoo::searchAnimalByName(const std::string &name) const
{
	for(auto iter = animals.begin() ; iter != animals.end() ; ++iter) {
		if((*iter)->getName()== name) {
			return true;
		}
	}
	return 0;

}

std::set<std::string> Zoo::findAnimalTypesByCount(int threshold) const
{
	std::set<std::string> animalByThreshold;
	for(auto iter= animalCount.begin() ; iter !=animalCount.end() ; ++iter) {

		if((*iter).second>threshold) {
			animalByThreshold.insert(iter->first);
		}

	}
	return animalByThreshold;
}

double Zoo::calculateAverageAge() const
{
	std::vector<int> ages;
	double sum=0;

	for(auto iter = animals.begin() ; iter != animals.end() ; ++iter) {

		sum= sum+(*iter)->getAge();

	}

	double avgAge= sum/animals.size();
	return avgAge;

}

std::vector<std::string> Zoo::sortAnimalsByAge() const
{
	std::vector<std::string> AnimalSortedByAge;

	std::map<int,std::vector<std::string>> animalWithAge;

	for(auto iter= animals.begin() ; iter != animals.end() ; ++iter) {

		animalWithAge[(*iter)->getAge()].push_back((*iter)->getName());
	}


	for(auto i=animalWithAge.rbegin() ;  i != animalWithAge.rend() ; ++i) {

		auto animalsWithSameAge=(*i).second;

		for(auto it=animalsWithSameAge.begin(); it != animalsWithSameAge.end() ; ++it) {
			AnimalSortedByAge.push_back(*it);
		}

	}

	return AnimalSortedByAge;
}
