#include <stdio.h>
#include "config.h"

//Giả lập các cảm biến luôn trả về một giá trị không đổi

int ReadSoilMoisture(){
    return 0; //Độ ẩm
};

int ReadAirTemperature(){
    return 36; //Nhiệt độ
};

int ReadButton1(){
    return 0; //Trạng thái của Button1
}

int ReadButton2(){
    return 1; //Trạng thái của Button2
}

