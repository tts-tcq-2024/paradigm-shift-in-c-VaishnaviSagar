#include <stdio.h>
#include <assert.h>

typedef struct {
    const char* parameter;
    float value;
    float lower;
    float upper;
} ParameterCheck;

typedef enum {
    LOW_SOC_BREACH,
    LOW_SOC_WARNING,
    NORMAL,
    HIGH_SOC_WARNING,
    HIGH_SOC_BREACH
} BatteryStatus;

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

const char* getStatusMessage(BatteryStatus status, const char* parameter) {
    const char* messages[] = {
        "Low %s - Breach",
        "Low %s - Warning",
        "Normal %s",
        "High %s - Warning",
        "High %s - Breach"
    };
    return messages[status];
}

void printStatusMessage(const char* parameter, float value, float lower, float upper) {
    BatteryStatus status = mapToBatteryStatus(value, lower, upper);
    const char* message = getStatusMessage(status, parameter);
    printf(message, parameter);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    ParameterCheck checks[] = {
        {"Temperature", temperature, 0, 45},
        {"State of Charge", soc, 20, 80},
        {"Charge Rate", chargeRate, 0, 0.8}
    };

    for (int i = 0; i < sizeof(checks) / sizeof(checks[0]); i++) {
        printStatusMessage(checks[i].parameter, checks[i].value, checks[i].lower, checks[i].upper);
    }

    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
