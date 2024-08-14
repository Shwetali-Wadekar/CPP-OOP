#ifndef SPEAKER_H_
#define SPEAKER_H_

#include "Device.h"

/**
 * Represents a speaker in the home electronics control system.
 */
class Speaker : public Device {
private:
    int volume; // Volume level from 0 to 100

public:
    /**
     * Creates a new speaker.
     *
     * @param id the speaker id
     * @param name the speaker name
     * @param volume the initial volume level
     */
    Speaker(const std::string& id, const std::string& name, int volume);

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

#endif /* SPEAKER_H_ */
