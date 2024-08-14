#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * Utility class for common helper functions.
 */
class Utils {
public:
    /**
     * Converts a string to uppercase.
     *
     * @param str the string to convert.
     * @return the uppercase version of the string.
     */
    static std::string toUpperCase(const std::string& str);

    /**
     * Checks if a string is a valid float.
     *
     * @param str the string to check.
     * @return true if the string is a valid float, false otherwise.
     */
    static bool isValidFloat(const std::string& str);
};

#endif // UTILS_H
