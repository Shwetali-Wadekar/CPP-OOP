// Standard (system) header files
#include <iostream>
#include <cstdlib>
// Add more standard header files as required
// #include <string>
#include<fstream>
#include"Measurement.h"
#include "Temperature.h"
#include "MeasurementDb.h"
#include "Humidity.h"
using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main ()
{
    // TODO: Add your program code here
	cout << "Exam-2019WiSe started." << endl << endl;

	Temperature measurement1(Measurement::toTimestamp(6,0),-3);
	cout<<measurement1.toString()<<endl;
	cout<<measurement1<<endl;

	std::shared_ptr<Measurement> m1= std::shared_ptr<Humidity> (new Humidity(Measurement::toTimestamp(8,0),80));
	std::shared_ptr<Measurement> m2= std::shared_ptr<Temperature> (new Temperature(Measurement::toTimestamp(10,5),20));
	std::shared_ptr<Measurement> m3= std::shared_ptr<Temperature> (new Temperature(Measurement::toTimestamp(12,0),22));
	cout<<endl;
	string location1="Kitchen";
	string location2="Bath";
	MeasurementDb db;
	db.addMeasurement(location1,m2);
	db.addMeasurement(location1,m3);
	db.addMeasurement(location2,m1);
	db.print();
	ofstream fb("data.txt");
	db.save(fb);

	MeasurementDb db2;
	ifstream dataread("data.txt");
	db2.load(dataread);

	ofstream fb2("datawrite.txt");
	db2.save(fb2);
	//db2.print();

	//maxtemp testing
	cout<<endl;
	string locationofmaxtemp;
	shared_ptr<Measurement> maxmeasure;
	db2.maximumTemperature(locationofmaxtemp,maxmeasure);
	cout<<locationofmaxtemp<<endl;
	cout<<*maxmeasure;

	return 0;
}
