#include "gender.h"

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
