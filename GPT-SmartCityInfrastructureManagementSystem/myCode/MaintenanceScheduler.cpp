/*
 * MaintenanceScheduler.cpp
 *
 *  Created on: 31 Jul 2024
 *      Author: hp
 */

#include "MaintenanceScheduler.h"

MaintenanceScheduler::MaintenanceScheduler(const std::chrono::seconds &intv) : interval(intv)
{
}

void MaintenanceScheduler::addElement(
		const std::shared_ptr<InfrastructureElement> &element)
{
	elements.push_back(element);
}

void MaintenanceScheduler::runScheduler() const
{
	while(true) {
		for(auto iter=elements.begin() ; iter != elements.end() ; ++iter) {
			(**iter).performMaintenance();
		}
		scheduleNextCheck();
	}

}

void MaintenanceScheduler::scheduleNextCheck() const
{
	std::this_thread::sleep_for(this->interval);
}
