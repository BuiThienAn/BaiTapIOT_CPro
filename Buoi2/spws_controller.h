#ifndef SPWS_CONTROLLER_H
#define SPWS_CONTROLLER_H

#include "config.h"

void SPWS_RunAutoMode(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData);

void SPWS_RunManualMode(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData, Button2_t previousButton2State);

#endif