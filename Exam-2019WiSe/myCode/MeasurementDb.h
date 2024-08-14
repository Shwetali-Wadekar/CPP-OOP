/*
 * MeasurementDb.h
 *
 *  Created on: 21 Jul 2024
 *      Author: hp
 */

#ifndef MEASUREMENTDB_H_
#define MEASUREMENTDB_H_
#include<map>
#include<memory>
#include<vector>
#include "Measurement.h"
class MeasurementDb
{
	std::map<std::string, std::vector<std::shared_ptr<Measurement>>> data;
public:
	void addMeasurement(const std::string& location, std::shared_ptr<Measurement> measurement);
	void print();
	void save(std::ostream& to);
	void load(std::istream& from);
	bool maximumTemperature(std::string& location, std::shared_ptr<Measurement>&measurement );
};

#endif /* MEASUREMENTDB_H_ */
