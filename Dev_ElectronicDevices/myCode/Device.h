#ifndef DEVICE_H_
#define DEVICE_H_

#include <string>
#include <memory>

/**
 * The base class for all electronic devices (TVs, speakers, etc.).
 */
class Device {
private:
    std::string id;
    std::string name;

protected:
    bool status;


public:
    /**
     * Creates a new device.
     *
     * @param id the device id
     * @param name the device name
     */
    Device(const std::string& id, const std::string& name);

    virtual ~Device();

    /**
     * Returns the device's id.
     */
    std::string getId() const;

    /**
     * Returns the device's name.
     */
    std::string getName() const;

    /**
     * Turns the device on.
     */
    virtual void turnOn() = 0;

    /**
     * Turns the device off.
     */
    virtual void turnOff() = 0;

    /**
     * Returns the current status of the device.
     *
     * @return the status
     */
    virtual bool getStatus() const = 0;
};

#endif /* DEVICE_H_ */
