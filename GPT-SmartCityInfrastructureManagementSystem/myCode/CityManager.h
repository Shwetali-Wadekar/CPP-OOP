/*
 * CityManager.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef CITYMANAGER_H_
#define CITYMANAGER_H_


#include <map>
#include <set>
#include <string>
#include <memory>
#include "Building.h"
#include "Road.h"
#include "TrafficLight.h"

/**
 * Manages the city's infrastructure elements.
 */
class CityManager {
private:
    std::map<std::string, std::shared_ptr<Building>> buildings;  // Key: Building ID, Value: Building pointer
    std::map<std::string, std::shared_ptr<Road>> roads;          // Key: Road ID, Value: Road pointer
    std::map<std::string, std::shared_ptr<TrafficLight>> trafficLights; // Key: Traffic Light ID, Value: Traffic Light pointer

public:
    /**
     * Add a building to the city manager.
     *
     * @param building A shared pointer to the building to be added.
     */
    void addBuilding(const std::shared_ptr<Building>& building);

    /**
     * Add a road to the city manager.
     *
     * @param road A shared pointer to the road to be added.
     */
    void addRoad(const std::shared_ptr<Road>& road);

    /**
     * Add a traffic light to the city manager.
     *
     * @param trafficLight A shared pointer to the traffic light to be added.
     */
    void addTrafficLight(const std::shared_ptr<TrafficLight>& trafficLight);

    /**
     * Perform maintenance on all infrastructure elements.
     * This method should call performMaintenance on each element.
     */
    void performMaintenance() const;

    /**
     * List all infrastructure elements and their statuses.
     * This method should print out the status of each building, road, and traffic light.
     */
    void listInfrastructure() const;

    /**
     * Get the number of buildings and roads that are under repair.
     *
     * @return A pair where the first element is the number of buildings under repair and the second element is the number of roads under repair.
     */
    std::pair<int, int> getRepairStatistics() const;
};
#endif /* CITYMANAGER_H_ */
