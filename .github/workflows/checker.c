#include <stdio.h>
#include <assert.h>

typedef struct {
 const char* parameter;
 float value;
 float lower;
 float upper;
} ParameterCheck;

int isOutOfRange(const ParameterCheck* param) {
 if (param->value < param->lower || param->value > param->upper) {
     printf("%s out of range!\n", param->parameter);
     return 1;
 }
 return 0;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 ParameterCheck checks[] = {
     {"Temperature", temperature, 0, 45},
     {"State of Charge", soc, 20, 80},
     {"Charge Rate", chargeRate, 0, 0.8}
 };

 for (int i = 0; i < sizeof(checks) / sizeof(checks[0]); i++) {
     if (isOutOfRange(&checks[i])) {
         return 0;
     }
 }
 return 1;
}

int main() {
 assert(batteryIsOk(25, 70, 0.7));
 assert(!batteryIsOk(50, 85, 0));
}
