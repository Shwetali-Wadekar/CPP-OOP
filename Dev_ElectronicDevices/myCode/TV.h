#ifndef TV_H_
#define TV_H_

#include "Device.h"

/**
 * Represents a TV in the home electronics control system.
 */
class TV : public Device {
private:
    int volume; // Volume level from 0 to 100

public:
    /**
     * Creates a new TV.
     *
     * @param id the TV id
     * @param name the TV name
     * @param volume the initial volume level
     */
    TV(const std::string& id, const std::string& name, int volume);

    /**
     * Sets the volume level.
     *
     * @param level the volume level
     */
    void setVolume(int level);

    /**
     * Gets the volume level.
     *
     * @return the volume level
     */
    int getVolume() const;

    void turnOn() override;
    void turnOff() override;
    bool getStatus() const override;
};

#endif /* TV_H_ */
