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
const char* getStatusMessage(BatteryStatus status, const char* parameter, const char* language) {
    switch (status) {
        case LOW_SOC_BREACH:
            if (strcmp(language, "en") == 0) {
                return "Low %s - Breach";
            } else if (strcmp(language, "fr") == 0) {
                return "Faible %s - Violation";
            }
            // Add more language cases as needed
        case LOW_SOC_WARNING:
            // Handle language translation for other statuses
        default:
            return "Unknown Status";
    }
}
const char* language = "en"; // Set the language to English
const char* message = getStatusMessage(status, parameter, language);
printf(message, parameter);
