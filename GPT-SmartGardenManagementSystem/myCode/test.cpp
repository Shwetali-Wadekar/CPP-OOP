#include <iostream>
#include <memory>
#include "Plant.h"
#include "Fountain.h"
#include "Gardener.h"
#include "MaintenanceScheduler.h"

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

/**
 * Tests for the GardenElement classes. (30 points)
 */
void gardenElementTests() {
    // Create instances of Plant and Fountain.
    // Ensure to test the initial state of each instance.

    // Plant Tests:
    // 1. Verify that a newly created Plant instance has a growth stage of 0.
    // 2. Call the `water()` method and then the `grow()` method. Verify that the growth stage increments correctly.
    // 3. Add a method `prune()` to the Plant class. Call `prune()` and verify its effect on the plant's state.

    // Fountain Tests:
    // 1. Verify that a newly created Fountain instance is inactive and has a flow rate of 0.
    // 2. Call the `activate()` method and `setFlowRate()` with a specific value. Verify that the Fountain's status and flow rate are updated correctly.
    // 3. Implement a method `deactivate()` in the Fountain class. Verify that calling `deactivate()` changes the Fountain's state to inactive and resets the flow rate.

    // Add code to verify the above points and assert conditions accordingly.
}

/**
 * Tests for the Gardener class. (20 points)
 */
void gardenerTests() {
    // Create a Gardener instance.
    // Add instances of Plant and Fountain to the Gardener's list of managed elements.

    // 1. Test that the Gardener can correctly perform maintenance on all managed elements.
    // 2. Implement a method `updateElementCondition` in the Gardener class. Verify that this method correctly updates the condition of a specified element.
    // 3. Implement a method `removeElement` in the Gardener class. Verify that this method correctly removes an element by name from the Gardener's list of managed elements.

    // Add code to verify the above points and assert conditions accordingly.
}

/**
 * Tests for the MaintenanceScheduler class. (20 points)
 */
void maintenanceSchedulerTests() {
    // Create a MaintenanceScheduler instance and add a Gardener instance to it.

    // 1. Add instances of Garden elements to the Gardener and schedule a maintenance task for a specific time.
    // 2. Call `executeScheduledTasks` with the scheduled time and verify that the correct tasks are executed.
    // 3. Implement a method `cancelScheduledTask` in the MaintenanceScheduler class. Verify that scheduled tasks can be canceled and are not executed after cancellation.

    // Add code to verify the above points and assert conditions accordingly.
}

void alltest() {
    // Run tests for GardenElement classes.
    gardenElementTests();

    // Run tests for Gardener class.
    gardenerTests();

    // Run tests for MaintenanceScheduler class.
    maintenanceSchedulerTests();

}
