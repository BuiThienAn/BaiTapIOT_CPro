#include <stdio.h>
#include "config.h"
#include "hal_actuators.h"

void SPWS_RunAutoMode(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData){
    //Chế độ AUTO thì liên tục switch-case để check trạng thái bơm
    //Khi bơm tắt thì CHỈ bật bơm khi độ ẩm thấp. Một khi đã bật bơm rồi thì bật bộ đếm thời gian
    //Khi bơm đang bật thì liên tục tăng bộ đếm thời gian
    //Bơm chỉ tắt khi độ ẩm cao hoặc đủ thời gian tưới 
    switch (pSystemState->pumpState){
        case PUMP_OFF:
            if (pSensorData->soilMoisturePercent < pSystemSettings->minMoistureThreshold) {
            TurnPumpOn(pSystemState);
            pSystemState->wateringTimeCounter = 0;
            };
            break;
        case PUMP_ON:
            pSystemState->wateringTimeCounter++;
            if ((pSensorData->soilMoisturePercent >= pSystemSettings->maxMoistureThreshold) || (pSystemState->wateringTimeCounter >= pSystemSettings->maxWateringDuration_s)){
            TurnPumpOff(pSystemState);
            };
            break;  
    };
};

void SPWS_RunManualMode(SystemSettings_t *pSystemSettings, SystemState_t *pSystemState, SensorData_t *pSensorData, Button2_t previousButton2State){
    //Bơm bật thì liên tục tăng bộ đếm thời gian tưới
    //Bơm chỉ tắt khi khi đủ thời gian tưới
    //Chế độ manual chỉ bắt đầu bật bơm khi: 
    //   1. Bơm tắt; 
    //   2. Nút nhấn 2 chuyển trạng thái từ tắt sang bật -> Sự kiện nhấn nút nhấn 2
    if(pSystemState->pumpState == PUMP_ON){
        pSystemState->wateringTimeCounter++;
        if (pSystemState->wateringTimeCounter >= pSystemSettings->manualWateringDuration_s){
            TurnPumpOff(pSystemState);
        };
    };

    if ((pSystemState->pumpState == PUMP_OFF) && (previousButton2State == BUTTON2_OFF) && (pSystemState->Button2 == BUTTON2_ON)){
        TurnPumpOn(pSystemState);
        pSystemState->wateringTimeCounter = 0; 
    };    
};

