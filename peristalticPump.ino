/************************************************************
**
**  @file peristalticPump.ino
**  @author Luis David Rodríguez-Centeno
**  @date 11/08/23
**  @version 2.0
**  @copyright Copyright (c) 2023
**
*************************************************************/
#include "pinNumbers.h"

int pwm1Value = 20;
int pwm2Value = 0;

// Global variables to set the initial conditions for the project

void timer()
{
    if (millis() - lastTime > 60000)
    {
        minutes++;
        lastTime = millis();
    }
    if (minutes > 60)
    {
        hours++;
        minutes = 0;
    }
    if (hours == 24)
    {
        hours = 0;
    }
    float minDecimal;
    minDecimal = float(minutes) / 60;
    totalTime = float(hours) + minDecimal;
}

void pumpControl(float time, float flowTime, int pump)
{
    if (time > flowTime)
    {
        digitalWrite(pump, pwm2Value);
    }
    else
    {
        digitalWrite(pump, pwm1Value);
    }
}

void setup()
{
    Serial.begin(9600);
    pinMode(pump1, OUTPUT);
    pinMode(pump2, OUTPUT);
    pinMode(pump3, OUTPUT);
    pinMode(pump4, OUTPUT);
}
void loop()
{
    timer();
    Serial.println(totalTime);
    Serial.println(minutes);
    Serial.println(hours);
    pumpControl(totalTime, vol1, pump1);
    pumpControl(totalTime, vol2, pump2);
    pumpControl(totalTime, vol3, pump3);
    pumpControl(totalTime, vol4, pump4);
}