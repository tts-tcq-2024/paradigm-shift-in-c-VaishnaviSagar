#ifndef BATTERYSTATUS_H
#define BATTERYSTATUS_H
typedef enum {
    LOW_SOC_BREACH,
    LOW_SOC_WARNING,
    NORMAL,
    HIGH_SOC_WARNING,
    HIGH_SOC_BREACH
} BatteryStatus;

