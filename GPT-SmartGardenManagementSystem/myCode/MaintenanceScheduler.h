/*
 * MaintenanceScheduler.h
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#ifndef MAINTENANCESCHEDULER_H_
#define MAINTENANCESCHEDULER_H_


#include <map>
#include <string>
#include <memory>
#include "Gardener.h"

/**
 * Represents a scheduling mechanism to manage garden maintenance.
 */
class MaintenanceScheduler {
private:
    std::map<std::string, std::shared_ptr<Gardener>> gardeners; // Map of gardeners by name.
    std::map<std::string, std::map<std::string, std::string>> schedule; // Map of scheduled tasks by time.

public:
    /**
     * Adds a gardener to the scheduler.
     * @param gardener A shared pointer to the gardener to be added.
     */
    void addGardener(const std::shared_ptr<Gardener>& gardener);

    /**
     * Schedules maintenance tasks for a specific time and gardener.
     * @param time The time at which the maintenance should be performed.
     * @param gardenerName The name of the gardener responsible.
     * @param action The action to be performed.
     */
    void scheduleMaintenance(const std::string& time, const std::string& gardenerName, const std::string& action);

    /**
     * Cancels all scheduled tasks for a specific time.
     * @param time The time at which tasks should be canceled.
     */
    void cancelScheduledTask(const std::string& time);

    /**
     * Executes scheduled maintenance tasks based on the current time.
     * @param currentTime The current time used to check and execute tasks.
     */
    void executeScheduledTasks(const std::string& currentTime) const;
};

#endif /* MAINTENANCESCHEDULER_H_ */
