/************************************************************
**
**  @file peristalticPump.ino
**  @author Luis David Rodríguez-Centeno
**  @date 08/30/23
**  @version 0.1
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

void pumpControl1()
{
    if (totalTime > vol1)
    {
        digitalWrite(pump1, pwm2Value);
    }
    else
    {
        digitalWrite(pump1, pwm1Value);
    }
}

void pumpControl2()
{
    if (totalTime > vol2)
    {
        digitalWrite(pump2, pwm2Value);
    }
    else
    {
        digitalWrite(pump2, pwm1Value);
    }
}

void pumpControl3()
{
    if (totalTime > vol3)
    {
        digitalWrite(pump3, pwm2Value);
    }
    else
    {
        digitalWrite(pump3, pwm1Value);
    }
}

void pumpControl4()
{
    if (totalTime > vol4)
    {
        digitalWrite(pump4, pwm2Value);
    }
    else
    {
        digitalWrite(pump4, pwm1Value);
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
    pumpControl1();
    pumpControl2();
    pumpControl3();
    pumpControl4();
}