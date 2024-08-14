/*
 * ResistorReader.cpp
 *
 *  Created on: 20 Jul 2024
 *      Author: hp
 */

#include "ResistorReader.h"
#include "ResistorPart.h"
#include "Resistor.h"
#include "SerialResistorConnection.h"
#include "ParallelResistorConnection.h"
#include "ResistorConnection.h"
#include<sstream>
using namespace std;
ResistorReader::ResistorReader()
{
	// TODO Auto-generated constructor stub

}

void ResistorReader::read(std::istream &in,
		std::map<std::string, Resistor::ResistorPtr> &found)
{
	std::string line;
	while(std::getline(in,line)) {
		if(line.find('[') == std::string::npos) {
			std::shared_ptr<Resistor> returnptr=ResistorPart::from(line);
			std::string resisterName= returnptr->getName();
			found.insert(std::make_pair(resisterName,returnptr));
		}else {
			if(line.find('-')!=std::string::npos) {
				std::istringstream iss(line);
				string rname;
				std::getline(iss,rname,';');


				std::istringstream iss2(rname);

				std::string connName;
				std::getline(iss2,connName,'[');
				SerialResistorConnection serial(connName);
				std::string allResistors;
				std::getline(iss2,allResistors,']');
				std::istringstream iss3(allResistors);
				string res;
				while(getline(iss3,res,'-')) {

					auto findResister=found.find(res);
					if(findResister != found.end()) {
						serial+=findResister->second;
					}
					found.erase(findResister);

				}
				std::shared_ptr<Resistor> r=shared_ptr<ResistorConnection>(new SerialResistorConnection(serial));
				found.insert(make_pair(connName,r));


			}else {
				std::istringstream iss(line);
				string rname;
				std::getline(iss,rname,';');


				std::istringstream iss2(rname);

				std::string connName;
				std::getline(iss2,connName,'[');
				ParallelResistorConnection serial(connName);
				std::string allResistors;
				std::getline(iss2,allResistors,']');
				std::istringstream iss3(allResistors);
				string res;
				while(getline(iss3,res,'|')) {

					auto findResister=found.find(res);
					if(findResister != found.end()) {
						serial+=findResister->second;
					}
					found.erase(findResister);

				}
				std::shared_ptr<Resistor> r2=shared_ptr<ResistorConnection>(new ParallelResistorConnection(serial));
				found.insert(make_pair(connName,r2));





			}
		}
	}









}
