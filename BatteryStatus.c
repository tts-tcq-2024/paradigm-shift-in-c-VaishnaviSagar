#include <BatteryStatus.h>
BatteryStatus mapToBatteryStatus(float value, float lower, float upper) {
    if (value < lower) {
        return LOW_SOC_BREACH;
    }
    if (value >= lower && value <= lower + 3) {
        return LOW_SOC_WARNING;
    }
    if (value > lower + 3 && value < upper - 5) {
        return NORMAL;
    }
    if (value >= upper - 5 && value <= upper) {
        return HIGH_SOC_WARNING;
    }
    return HIGH_SOC_BREACH;
}


