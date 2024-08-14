#ifndef HOMECONTROLLER_H_
#define HOMECONTROLLER_H_

#include <vector>
#include <memory>
#include <unordered_map>
#include "Device.h"

/**
 * Manages all devices in the home electronics control system.
 */
class HomeController {
private:
    std::unordered_map<std::string, std::unique_ptr<Device>> devices;

public:
    /**
     * Adds a device to the home controller.
     *
     * @param device the device to add
     */
    void addDevice(std::unique_ptr<Device> device);

    /**
     * Gets a device by its id.
     *
     * @param id the device id
     * @return the device
     */
    Device* getDevice(const std::string& id) const;

    /**
     * Turns on all devices.
     */
    void turnOnAllDevices();

    /**
     * Turns off all devices.
     */
    void turnOffAllDevices();

    /**
     * Gets the status of all devices.
     *
     * @return a vector of device statuses
     */
    std::vector<bool> getAllStatuses() const;
};

#endif /* HOMECONTROLLER_H_ */
