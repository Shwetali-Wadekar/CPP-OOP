/*
 * test.cpp
 *
 *  Created on: 1 Aug 2024
 *      Author: hp
 */



#include "SmartHome.h"
#include "Light.h"
#include "ComplexAppliance.h"
#include "User.h"
#include "EnergyConsumption.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <memory>
#include <stdexcept>
#include <Poco/DateTime.h>

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const string& failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the Appliance classes. (XX points)
 */
void applianceTests() {
    /*
     * (1) Create instances of Light and ComplexAppliance classes with various attributes.
     *     Verify that their IDs, names, and specific attributes (powerUsage) are correctly set.
     *     Ensure that the getEnergyConsumption method works correctly for both classes.
     *     (20 points)
     */
	Light tubelight("t1","tubelight",36);
	Light bulb("b1","bulb",100);
	ComplexAppliance fridge("f1","fridge",500);

	assertTrue(tubelight.getId()=="t1","id not matched");
	assertTrue(tubelight.getName()=="tubelight","name not matched");
	assertTrue(tubelight.getEnergyConsumption(1)==0.036,"energy consumption not matched");

	assertTrue(fridge.getId()=="f1","id not matched");
	assertTrue(fridge.getName()=="fridge","name not matched");
	assertTrue(fridge.getEnergyConsumption(1)==0.5,"energy consumption not matched");



    /*
     * (2) Test the toggle method for the Light class to ensure it changes the state correctly.
     *     Ensure that the isActive method reflects the correct state of the Light.
     *     (10 points)
     */
	assertTrue(bulb.isActive()==0,"bulb is not off before");
	bulb.toggle();
	assertTrue(bulb.isActive()==1,"bulb should be on");
	bulb.toggle();
	assertTrue(bulb.isActive()==0,"bulb should be off");






}

/**
 * Tests for the SmartHome class. (XX points)
 */
void smartHomeTests() {
    /*
     * (1) Create a SmartHome "Eco House" and add various appliances and users.
     *     Verify the addition of appliances and users and ensure attributes are correctly set.
     *     (20 points)
     */
	SmartHome home("Eco House");
	Light* tubelight= new Light("t1","tubelight",36);
	Light* bulb=new Light("b1","bulb",100);
	ComplexAppliance* fridge= new ComplexAppliance("f1","fridge",500);
	ComplexAppliance* washingmaschine= new ComplexAppliance("w1","washingmaschine",1200);
	ComplexAppliance* tv= new ComplexAppliance("tv1","tv",150);
	Light* led=new Light("led1","led",10);

	User* bhavin=new User("1","bhavin");
	User* rutvik=new User("2","rutvik");
	User* dev=new User("3","dev");

	home.addAppliance(std::shared_ptr<Appliance>(tubelight));
	home.addAppliance(std::shared_ptr<Appliance>(bulb));
	home.addAppliance(std::shared_ptr<Appliance>(fridge));
	home.addAppliance(std::shared_ptr<Appliance>(washingmaschine));
	home.addAppliance(std::shared_ptr<Appliance>(tv));
	home.addAppliance(std::shared_ptr<Appliance>(led));

	home.registerUser(std::shared_ptr<User>(bhavin));
	home.registerUser(std::shared_ptr<User>(rutvik));
	home.registerUser(std::shared_ptr<User>(dev));

	assertTrue(home.getAppliance("b1")!=nullptr,"appliance should be added");
	assertTrue(home.getAppliance("t1")!=nullptr,"appliance should be added");







    /*
     * (2) Test the assignApplianceToUser method to ensure appliances are assigned correctly.
     *     (10 points)
     */

	home.assignApplianceToUser("b1","1");
	home.assignApplianceToUser("t1","1");
	home.assignApplianceToUser("f1","1");
	home.assignApplianceToUser("w1","1");
	home.assignApplianceToUser("tv1","1");
	home.assignApplianceToUser("led1","1");
	home.assignApplianceToUser("b1","2");

	assertTrue(home.getAppliancesForUser("1").size()==6,"appliance not assigned for user");

    /*
     * (3) Record energy consumption for an appliance and calculate total energy consumption for a user.
     *     Verify correct recording and calculation of energy consumption.
     *     (20 points)
     */
    EnergyConsumption* bulbConsumption= new EnergyConsumption("b1", Poco::DateTime(2024,8,1,0,0,0), Poco::DateTime(2024,8,1,23,0,0));
    EnergyConsumption* tubelightconusmption= new EnergyConsumption("t1", Poco::DateTime(2024,8,1,0,0,0), Poco::DateTime(2024,8,1,23,0,0));
    EnergyConsumption* fridgeconsumption= new EnergyConsumption("f1", Poco::DateTime(2024,8,1,0,0,0), Poco::DateTime(2024,8,1,23,0,0));
    EnergyConsumption* washingmachineconsumption= new EnergyConsumption("w1", Poco::DateTime(2024,8,1,0,0,0), Poco::DateTime(2024,8,1,23,0,0));
    EnergyConsumption* tvConsumption= new EnergyConsumption("tv1", Poco::DateTime(2024,8,1,0,0,0), Poco::DateTime(2024,8,1,23,0,0));
    EnergyConsumption* ledConsumption= new EnergyConsumption("led1", Poco::DateTime(2024,8,1,0,0,0), Poco::DateTime(2024,8,1,23,0,0));

    home.recordEnergyConsumption(std::unique_ptr<EnergyConsumption>(bulbConsumption));
    home.recordEnergyConsumption(std::unique_ptr<EnergyConsumption>(tubelightconusmption));
    home.recordEnergyConsumption(std::unique_ptr<EnergyConsumption>(fridgeconsumption));
    home.recordEnergyConsumption(std::unique_ptr<EnergyConsumption>(washingmachineconsumption));
    home.recordEnergyConsumption(std::unique_ptr<EnergyConsumption>(tvConsumption));
    home.recordEnergyConsumption(std::unique_ptr<EnergyConsumption>(ledConsumption));





    double expectedEnergyConsumptionForRutvik = 0.1*23;
    double expectedEnergyConsumptionForBhavin = (0.1+0.036+0.5+1.2+0.15+0.010)*23;

   assertTrue(home.totalEnergyConsumptionForUser("2")==expectedEnergyConsumptionForRutvik,"engeryconsumption for user incorrect");
   assertTrue(home.totalEnergyConsumptionForUser("1")==expectedEnergyConsumptionForBhavin,"engeryconsumption for user incorrect");

   //cout<<home.totalEnergyConsumptionForUser("gva");

}

/**
 * Comprehensive tests involving multiple relationships. (XX points)
 */
void comprehensiveTests() {

	/*
     * (1) Create a SmartHome system where users interact with various appliances and energy consumption is recorded.
     *     Verify the complex relationships and interactions among users, appliances, and energy records.
     *     Use a mix of algorithms (like searching and sorting) to ensure complex interactions are handled correctly.
     *     (20 points)
     */

}

void allTests() {
    applianceTests();
    smartHomeTests();
    comprehensiveTests();
}

