/*
 * MeasurementDb.cpp
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#include "MeasurementDb.h"
#include"Temperature.h"
#include "Humidity.h"
using namespace std;
#include <iostream>
// 	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;

void MeasurementDb::addMeasurement(const std::string &location,
		std::shared_ptr<Measurement> measurement)
{
	data[location].push_back(measurement);
}

void MeasurementDb::print()
{
	cout<<"Content of database:"<<endl;
	for(auto iter= data.begin() ; iter != data.end() ; ++iter) {
		std::vector<std::shared_ptr<Measurement>> measurements= (*iter).second;
		for(auto i= measurements.begin() ; i != measurements.end() ; ++i) {

			cout<<iter->first<<": "<<(**i)<<endl;

		}

	}
}

void MeasurementDb::save(std::ostream &to)
{
	for(auto iter= data.begin() ; iter != data.end() ; ++iter) {
		to<<"["<<iter->first<<"]"<<endl;
		std::vector<std::shared_ptr<Measurement>> measurements= (*iter).second;
		for(auto i= measurements.begin() ; i != measurements.end() ; ++i) {

			//cout<<iter->first<<": "<<(**i)<<endl;
			to<<(**i).getTimestamp()<<";"<<(**i).toString()<<endl;

		}
	}

}

void MeasurementDb::load(std::istream &from)
{
	data.clear();
	string line;
	string location;

	while(getline(from,line)) {

		if(line.find('[') != string::npos) {
			location=line.substr(line.find('[')+1,line.find(']')-1);

		}else {
			uint16_t timestamp;
			string type;
			string reminder;
			Measurement::parseLine(line,timestamp,type,reminder);

			if(type == "Temperature") {
				std::shared_ptr<Temperature> measurement=Temperature::fromString(timestamp,reminder);
				addMeasurement(location,measurement);
			}else if(type == "Humidity" ){
				std::shared_ptr<Humidity> measurement=Humidity::fromString(timestamp,reminder);
				addMeasurement(location,measurement);
			}

		}
	}
}

bool MeasurementDb::maximumTemperature(std::string &location,
		std::shared_ptr<Measurement> &measurement)
{
	bool returnbool=false;
	float maxtemp=0;
	for(auto iter= data.begin() ; iter != data.end() ; ++iter) {
		std::vector<std::shared_ptr<Measurement>> measurements= (*iter).second;

		for(auto i= measurements.begin() ; i != measurements.end() ; ++i) {
			if(Temperature::toType((*i).get()) != nullptr) {
				returnbool=true;
				Temperature* pTemp = Temperature::toType((*i).get());
				if(maxtemp<pTemp->getTemperature()) {
					maxtemp= pTemp->getTemperature();
					measurement=(*i);
					location=(*iter).first;
				}
			}
		}



	}
	return returnbool;

}
