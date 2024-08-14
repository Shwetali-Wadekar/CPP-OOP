/*
 * MaintenanceScheduler.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef MAINTENANCESCHEDULER_H_
#define MAINTENANCESCHEDULER_H_


#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include "InfrastructureElement.h"

/**
 * Scheduler for managing and executing maintenance tasks.
 */
class MaintenanceScheduler {
private:
    std::vector<std::shared_ptr<InfrastructureElement>> elements; // List of infrastructure elements to be maintained
    std::chrono::seconds interval; // Interval between maintenance checks

public:
    /**
     * Constructor for the MaintenanceScheduler class.
     *
     * @param intv Time interval between maintenance checks.
     */
    MaintenanceScheduler(const std::chrono::seconds& intv);

    /**
     * Add an infrastructure element to the scheduler.
     *
     * @param element A shared pointer to the infrastructure element to be added.
     */
    void addElement(const std::shared_ptr<InfrastructureElement>& element);

    /**
     * Run the scheduler to perform maintenance on all elements.
     * This method should run indefinitely, performing maintenance at the specified interval.
     */
    void runScheduler() const;

    /**
     * Schedule the next maintenance check.
      */
    void scheduleNextCheck() const;
};
#endif /* MAINTENANCESCHEDULER_H_ */
