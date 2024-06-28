#include <stdio.h>
#include <assert.h>

#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

typedef struct {
    float min;
    float max;
    const char* name;
} Range;

const Range TEMP_RANGE = {TEMP_MIN, TEMP_MAX, "Temperature"};
const Range SOC_RANGE = {SOC_MIN, SOC_MAX, "State of Charge"};
const Range CHARGE_RATE_RANGE = {0, CHARGE_RATE_MAX, "Charge Rate"};

int isInRange(float value, Range range) {
    return (value >= range.min && value <= range.max);
}

void printWarning(const char* message) {
    printf("%s out of range!\n", message);
}

int checkAndWarn(float value, Range range) {
    if (!isInRange(value, range)) {
        printWarning(range.name);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkAndWarn(temperature, TEMP_RANGE) &&
           checkAndWarn(soc, SOC_RANGE) &&
           checkAndWarn(chargeRate, CHARGE_RATE_RANGE);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
