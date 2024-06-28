#include <stdio.h>
#include <assert.h>

#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

int isInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

int checkTemperature(float temperature) {
    if (!isInRange(temperature, TEMP_MIN, TEMP_MAX)) {
        printf("Temperature out of range!\n");
        return 0;
    }
    return 1;
}

int checkStateOfCharge(float soc) {
    if (!isInRange(soc, SOC_MIN, SOC_MAX)) {
        printf("State of Charge out of range!\n");
        return 0;
    }
    return 1;
}

int checkChargeRate(float chargeRate) {
    if (chargeRate > CHARGE_RATE_MAX) {
        printf("Charge Rate out of range!\n");
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return checkTemperature(temperature) &&
           checkStateOfCharge(soc) &&
           checkChargeRate(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
