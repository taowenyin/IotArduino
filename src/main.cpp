#include <Arduino.h>
#include <Bridge.h>
#include <stdio.h>

char LEDState[2] = {0}; // LED的值
int LEDValue = -1;

void setup() {
    // 初始化LED灯
    pinMode(LED_BUILTIN, OUTPUT);

    // 初始化串口的值
    Serial.begin(115200);

    // Yun桥梁初始化
    Bridge.begin();
}

void loop() {
    // 读取当前从Bridge传来的数据
    Bridge.get("LED", LEDState, 2);
    LEDValue = atoi(LEDState);

    // 当传递过来的值为1时表示开灯，为0时表示关灯
    if(LEDValue != 0) {
        if(LEDValue == 1) { // LED亮
            digitalWrite(LED_BUILTIN, 1);
        }
        if(LEDValue == 2) { // LED灭
            digitalWrite(LED_BUILTIN, 0);
        }

        Serial.println("Data is " + LEDValue);
    } else {
        Serial.println("Data is 0");
    }

    delay(50);
}