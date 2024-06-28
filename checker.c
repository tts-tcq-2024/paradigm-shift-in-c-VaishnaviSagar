#include <stdio.h>
#include <assert.h>

#define TEMP_MIN 0
#define TEMP_MAX 45
#define SOC_MIN 20
#define SOC_MAX 80
#define CHARGE_RATE_MAX 0.8

int batteryIsOk(float temperature, float soc, float chargeRate) {
    return (temperature >= TEMP_MIN && temperature <= TEMP_MAX &&
            soc >= SOC_MIN && soc <= SOC_MAX &&
            chargeRate <= CHARGE_RATE_MAX);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    return 0;
}
