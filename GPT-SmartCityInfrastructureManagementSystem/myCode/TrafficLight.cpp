/*
 * TrafficLight.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "TrafficLight.h"
#include<iostream>
TrafficLight::TrafficLight(const std::string &id, const std::string &loc) : InfrastructureElement(id,loc)
{
	currentState=TrafficLight::LightState::RED;
}

std::string TrafficLight::getStatus() const
{
	if(currentState==LightState::GREEN) {
		return "GREEN";
	}else if( currentState== LightState::RED) {
		return "RED";
	}
	return "YELLOW";

}

void TrafficLight::performMaintenance() const
{	std::cout<<"under maintanace"<<std::endl;

}

void TrafficLight::changeState()
{
	if(currentState==LightState::GREEN) {
		currentState=LightState::YELLOW;
	}else if(currentState== LightState::RED) {
		currentState=LightState::GREEN;
	}else if(currentState==LightState::YELLOW) {
		currentState=LightState::RED;
	}
}
