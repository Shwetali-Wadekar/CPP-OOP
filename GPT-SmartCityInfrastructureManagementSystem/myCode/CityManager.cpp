/*
 * CityManager.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "CityManager.h"
#include<iostream>
//
//    std::map<std::string, std::shared_ptr<Building>> buildings;  // Key: Building ID, Value: Building pointer
//    std::map<std::string, std::shared_ptr<Road>> roads;          // Key: Road ID, Value: Road pointer
//    std::map<std::string, std::shared_ptr<TrafficLight>> trafficLights; // Key: Traffic Light ID, Value: Traffic Light pointer
//

using namespace std;

void CityManager::addBuilding(const std::shared_ptr<Building> &building)
{
	buildings.insert(make_pair(building->getID(),building));
}

void CityManager::addRoad(const std::shared_ptr<Road> &road)
{
	roads.insert(make_pair(road->getID(),road));
}

void CityManager::addTrafficLight(
		const std::shared_ptr<TrafficLight> &trafficLight)
{
	trafficLights.insert(make_pair(trafficLight->getID(),trafficLight));
}

void CityManager::performMaintenance() const {
    // Perform maintenance on all buildings

	for(auto i=buildings.begin() ; i != buildings.end() ; ++i) {
		(*i).second->performMaintenance();
	}

	for(auto i=roads.begin() ; i != roads.end() ; ++i) {
		(*i).second->performMaintenance();
	}

	for(auto i=trafficLights.begin() ; i != trafficLights.end() ; ++i) {
		(*i).second->performMaintenance();
	}

}

void CityManager::listInfrastructure() const
{
    std::cout << "Buildings:" << std::endl;
    for ( auto& building : buildings) {
        std::cout << building.second->getStatus() << std::endl;
    }

    // List all roads
    std::cout << "Roads:" << std::endl;
    for ( auto& road : roads) {
        std::cout << road.second->getStatus() << std::endl;
    }

    // List all traffic lights
    std::cout << "Traffic Lights:" << std::endl;
    for ( auto& trafficLight : trafficLights) {
        std::cout << trafficLight.second->getStatus() << std::endl;
    }
}

std::pair<int, int> CityManager::getRepairStatistics() const
{
	int buildingsUnderRepair=0;
	int roadUnderRepair=0;

	for(auto i=buildings.begin() ; i != buildings.end() ; ++i) {

		if((*i).second->getStatus()=="Building is Occupied!") {
			buildingsUnderRepair++;
		}
	}

	for(auto i=roads.begin() ; i != roads.end() ; ++i) {
		if((*i).second->getStatus()=="Under repair!") {
			roadUnderRepair++;
		}
	}
	return std::make_pair(buildingsUnderRepair,roadUnderRepair);
}
