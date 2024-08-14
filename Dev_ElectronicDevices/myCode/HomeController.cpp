#include "HomeController.h"
//    std::unordered_map<std::string, std::unique_ptr<Device>> devices;
using namespace std;
void HomeController::addDevice(std::unique_ptr<Device> device)
{
	string id= device->getId();
	devices.insert(make_pair(id,move(device)));
}

Device* HomeController::getDevice(const std::string &id) const
{
	auto found = devices.find(id);

	if( found != devices.end()) {
		return found->second.get();
	}else {
		return nullptr;
	}
}

void HomeController::turnOnAllDevices()
{
	for(auto iter = devices.begin(); iter != devices.end(); ++iter){
		(*iter).second->turnOn();
	}
}

void HomeController::turnOffAllDevices()
{
	for(auto iter = devices.begin(); iter != devices.end(); ++iter){
		(*iter).second->turnOff();
	}
}

std::vector<bool> HomeController::getAllStatuses() const
{
	std::vector<bool> allStatus;
	for(auto iter = devices.begin(); iter != devices.end(); ++iter){
		allStatus.push_back((*iter).second->getStatus());
	}
	return allStatus;
}
