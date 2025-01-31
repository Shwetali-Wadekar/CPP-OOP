#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

#include "TV.h"
#include "Speaker.h"
#include "DeviceFactory.h"
#include "HomeController.h"
#include "DeviceException.h"

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, const std::string& failedMessage) {
    if (!condition) {
        std::cout << failedMessage << std::endl;
    }
}

void deviceTests() {
    auto tv = DeviceFactory::createTV("Living Room TV", 50);
    auto speaker = DeviceFactory::createSpeaker("Bedroom Speaker", 20);

    // TV tests
    tv->turnOn();
    assertTrue(tv->getStatus() == true, "TV should be on.");
    tv->setVolume(75);
    assertTrue(tv->getVolume() == 75, "TV volume should be 75.");
    tv->turnOff();
    assertTrue(tv->getStatus() == false, "TV should be off.");

    // Speaker tests
    speaker->turnOn();
    assertTrue(speaker->getStatus() == true, "Speaker should be on.");
    speaker->setVolume(30);
    assertTrue(speaker->getVolume() == 30, "Speaker volume should be 30.");
    speaker->turnOff();
    assertTrue(speaker->getStatus() == false, "Speaker should be off.");
}

void homeControllerTests() {
    HomeController controller;

    auto tv = DeviceFactory::createTV("Living Room TV", 50);
    auto speaker = DeviceFactory::createSpeaker("Bedroom Speaker", 20);

    controller.addDevice(std::move(tv));
    controller.addDevice(std::move(speaker));

    // Test turning on all devices
    controller.turnOnAllDevices();
    auto statuses = controller.getAllStatuses();
    for (auto status : statuses) {
        assertTrue(status == true, "All devices should be on.");
    }

    // Test turning off all devices
    controller.turnOffAllDevices();
    statuses = controller.getAllStatuses();
    for (auto status : statuses) {
        assertTrue(status == false, "All devices should be off.");
    }

    // Test exceptions for invalid device actions
    try {
        auto tv = DeviceFactory::createTV("Invalid TV", 50);
        tv->setVolume(150);
        assertTrue(false, "exception not thrown");
    } catch (const DeviceException& e) {

    }

    try {
        auto speaker = DeviceFactory::createSpeaker("Invalid Speaker", 20);
        speaker->setVolume(200);
        assertTrue(false, "exception not thrown");
    } catch (const DeviceException& e) {

    }
}

void allTests(){
	deviceTests();
	homeControllerTests();
}



