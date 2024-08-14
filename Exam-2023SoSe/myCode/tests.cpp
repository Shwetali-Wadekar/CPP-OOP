#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

#include "TestSensor.h"
#include "LinearAdjuster.h"
#include "TableBasedAdjuster.h"
#include "SensorNetwork.h"
#include "DuplicateSensorName.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Tests for the adjustor classes. (12 points)
 */
void adjusterTests() {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using the test values given above as samples, assert that a
     * NullAdjustor's adjust method returns the argument's value
     * unchanged.
     */
    // TODO

    std::shared_ptr<Adjuster> na=NullAdjuster::sharedInstance;
    for( auto i=0; i<5 ; i++) {
        assertTrue(na.get()->adjust(testValues[i])==testValues[i]," null adjuster adjust value wrong" );
    }


    /*
     * (2) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with a single breakpoint (0,0) returns
     * the same values as a NullAdjustor.
     */
    // TODO
    NullAdjuster na2;

    TableBasedAdjuster ta;
    ta.addBreakpoint(0,0);

    for( auto i=0; i<5 ; i++) {
        assertTrue(ta.adjust(testValues[i])==na2.adjust(testValues[i]),"tablebased adjuster does not return same value as null adjuster");
    }
    /*
     * (3) Using the test values given above as samples, assert that a
     * TableBasedAdjustor with breakpoints (-100,-110), (0,0)
     * and (100,90) returns the given expected values.
     *
     * Remember (from your basic C/C++ courses) that floating
     * point calculations do not always yield exact results
     * (rounding errors due to using the binary system).
     * Take this into account when checking the result.
     */
    float expected[] = { -11, -1.1, 0, 0.9, 9 };
    // TODO

    TableBasedAdjuster tAdjuster;
    tAdjuster.addBreakpoint(-100,-110).addBreakpoint(0,0).addBreakpoint(100,90);

    for( auto i=0; i<5 ; i++) {

        assertTrue(((tAdjuster.adjust(testValues[i]))-(expected[i]))<0.00001,"TableBased adjuster value should be same as expected" );
        std::cout<<tAdjuster.adjust(testValues[i])-(expected[i])<<" ";
    }

}

/**
 * Tests for the sensor classes. (12 points)
 */
void sensorTests () {

    /*
     * Values for subsequent tests.
     */
    float testValues[] = { -10, -1, 0, 1, 10 };

    /*
     * (1) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a NullAdjustor returns the raw
     * readings of a sensor as readings.
     */
    // TODO
    std::shared_ptr<Adjuster> adj= NullAdjuster::sharedInstance;
    TestSensor s1("temperatureSensor",adj);

    for( auto i=0; i<5 ; i++) {

        s1.setRawReading(testValues[i]);
        //std::cout<<s1.reading()<<" "<<s1.rawReading()<<endl;
        assertTrue( s1.reading() == s1.rawReading() , " reading and rawreading does not matched");

    }


    /*
     * (2) Using a TestSensor and the test values given above as samples,
     * assert that a (test) sensor with a LinearAdjustor returns the
     * expected readings. Test with 10 differently configured
     * LinearAdjustors for each test value for exhaustive testing
     * (50 "assertTrue" invocations in total).
     */
    // TODO
    //LinearAdjuster adjLin()

    for(auto i=0; i<5 ; i++) {

        for( float offset=0; offset <10 ; offset++) {
            LinearAdjuster la(2,offset);
            std::shared_ptr<Adjuster> linAdj= std::shared_ptr<LinearAdjuster> (new LinearAdjuster(la));
            TestSensor s2("sensor",linAdj);
            s2.setRawReading(testValues[i]);
            //cout<<s2.reading()<<" "<<s2.rawReading()<<endl;
            assertTrue( s2.reading()== float(testValues[i]*2+offset),"linear adjuster not working");

        }

    }

}

/**
 * Tests for the sensor network. (16 points)
 */
void networkTests() {
    /*
     * Create a sensor network with 10 TestSensors named
     * "Thermometer n" (with n being the number of the thermometer)
     * that have their readings set to values 20 + n * 0.05.
     */
    // TODO

    SensorNetwork nw;
    for( int i=1 ; i<11;i++) {
        string sensorname="Thermometer"+to_string(i);
        std::shared_ptr<Adjuster> adj= NullAdjuster::sharedInstance;
        adj.get()->adjust(20+i*0.05);
        std::unique_ptr<Sensor> sensor= std::unique_ptr<TestSensor>(new TestSensor(sensorname,adj));
        nw.add(move(sensor));
    }

    /*
     * (1) Assert that adding a sensor with a name that is already
     * used by a sensor in the network throws a DuplicateSensorName
     * exception with the sensor's name as "what".
     */
    // TODO
    std::shared_ptr<Adjuster> adj1= NullAdjuster::sharedInstance;

    std::unique_ptr<Sensor> sensor1= std::unique_ptr<TestSensor>(new TestSensor("Thermometer1",adj1));
    std::string exp;
    try{
    nw.add(move(sensor1));
    }catch (  std::invalid_argument& e) {
        exp=e.what();

    }
    assertTrue("Duplicate sensor name: Thermometer1"==exp," exception does not occur");

}

void allTests() {
    adjusterTests();
    sensorTests();
    networkTests();
}
