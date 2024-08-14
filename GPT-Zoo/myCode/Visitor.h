/*
 * Visitor.h
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */

#ifndef VISITOR_H_
#define VISITOR_H_


#include <string>
#include <set>

/**
 * Represents a visitor to the zoo.
 */
class Visitor {
private:
    std::string name;
    int age;
    std::set<std::string> visitedZoos;

public:
    Visitor(std::string name, int age);

    std::string getName() const;
    int getAge() const;

    /**
     * Add a zoo to the list of visited zoos.
     */
    void visitZoo(const std::string& zooName);

    /**
     * Return the list of visited zoos.
     */
    std::set<std::string> getVisitedZoos() const;

    /**
     * Check if the visitor has visited a given zoo.
     * Return true if visited, false otherwise.
     */
    bool hasVisitedZoo(const std::string& zooName) const;
};

#endif /* VISITOR_H_ */
