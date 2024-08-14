#ifndef DEVICEFACTORY_H_
#define DEVICEFACTORY_H_

#include <string>
#include <memory>
#include "TV.h"
#include "Speaker.h"

/**
 * Factory class to create devices with unique IDs.
 */
class DeviceFactory {
private:
    static int idCounter;

    /**
     * Generates a unique ID for a device.
     *
     * @return the unique ID
     */
    static std::string generateId();

public:
    /**
     * Creates a new TV with a unique ID.
     *
     * @param name the TV name
     * @param volume the initial volume level
     * @return the TV
     */
    static std::unique_ptr<TV> createTV(const std::string& name, int volume);

    /**
     * Creates a new speaker with a unique ID.
     *
     * @param name the speaker name
     * @param volume the initial volume level
     * @return the speaker
     */
    static std::unique_ptr<Speaker> createSpeaker(const std::string& name, int volume);
};

#endif /* DEVICEFACTORY_H_ */
