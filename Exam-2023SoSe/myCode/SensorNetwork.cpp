#include "SensorNetwork.h"
#include "DuplicateSensorName.h"
#include <algorithm>
SensorNetwork& SensorNetwork::add(std::unique_ptr<Sensor> &&sensor) {

    std::string sensorName=sensor.get()->getName();

    //auto findsensor= find(sensors.begin() , sensors.end() , sensor)

    for( auto i = sensors.begin() ; i != sensors.end() ; ++i) {

        if(sensorName ==(**i).getName()) {
            throw DuplicateSensorName(sensorName);
        }
    }

    sensors.push_back(std::move(sensor));
    return *this;
}
