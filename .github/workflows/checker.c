#include <stdio.h>
#include <assert.h>

int isOutOfRange(float value, float lower, float upper, const char* message) {
 if (value < lower || value > upper) {
     printf("%s out of range!\n", message);
     return 1;
 }
 return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 if (isOutOfRange(temperature, 0, 45, "Temperature") || 
     isOutOfRange(soc, 20, 80, "State of Charge") || 
     isOutOfRange(chargeRate, 0, 0.8, "Charge Rate")) {
     return 0;
 }
 return 1;
}

int main() {
 assert(batteryIsOk(25, 70, 0.7));
 assert(!batteryIsOk(50, 85, 0));
}
