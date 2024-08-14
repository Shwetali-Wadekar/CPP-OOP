#ifndef STRINGENCODER_H
#define STRINGENCODER_H

#include <string>
#include <stdexcept>

/**
 * Represents a class to handle character encoding conversions.
 */
class StringEncoder {
public:
    /**
     * Encodes a given UTF-8 string to UTF-16.
     *
     * @param utf8Str the UTF-8 encoded string.
     * @return the UTF-16 encoded string.
     * @throws std::runtime_error if the encoding fails.
     */
    static std::u16string encodeToUTF16(const std::string& utf8Str);

    /**
     * Decodes a given UTF-16 string to UTF-8.
     *
     * @param utf16Str the UTF-16 encoded string.
     * @return the UTF-8 encoded string.
     * @throws std::runtime_error if the decoding fails.
     */
    static std::string decodeFromUTF16(const std::u16string& utf16Str);
};

#endif // STRINGENCODER_H
