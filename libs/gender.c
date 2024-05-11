#include "gender.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

const char* gender_str(int gender) {
    switch (gender) {
        case GENDER_MALE:
            return "male";
        case GENDER_FEMALE:
            return "female";
        default:
            return "unknown";
    }
}

