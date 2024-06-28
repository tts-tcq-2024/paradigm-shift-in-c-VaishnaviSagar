#include <stdio.h>
#include <assert.h>

#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

int isTemperatureOk(float temperature) {
    return (temperature >= TEMP_MIN && temperature <= TEMP_MAX);
}

int isSocOk(float soc) {
    return (soc >= SOC_MIN && soc <= SOC_MAX);
}

int isChargeRateOk(float chargeRate) {
    return (chargeRate <= CHARGE_RATE_MAX);
}

void printWarning(const char* message) {
    printf("%s out of range!\n", message);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (!isTemperatureOk(temperature)) {
        printWarning("Temperature");
        return 0;
    }
    if (!isSocOk(soc)) {
        printWarning("State of Charge");
        return 0;
    }
    if (!isChargeRateOk(chargeRate)) {
        printWarning("Charge Rate");
        return 0;
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
