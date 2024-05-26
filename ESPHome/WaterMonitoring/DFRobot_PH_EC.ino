/*!
 * @file DFRobot_PH_EC.h
 * @brief This is the sample code for The Mixed use of two sensors:
 * @n 1. Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2
 * @n 2. Analog Electrical Conductivity Sensor / Meter Kit V2 (K=1.0), SKU: DFR0300.
 * @n In order to guarantee precision, a temperature sensor such as DS18B20 is needed, to execute automatic temperature compensation.
 * @n Serial Commands:
 * @n   PH Calibration：
 * @n    enterph -> enter the calibration mode
 * @n    calph   -> calibrate with the standard buffer solution, two buffer solutions(4.0 and 7.0) will be automaticlly recognized
 * @n    exitph  -> save the calibrated parameters and exit from calibration mode
 * @n   EC Calibration：
 * @n    enterph -> enter the PH calibration mode
 * @n    calph   -> calibrate with the standard buffer solution, two buffer solutions(4.0 and 7.0) will be automaticlly recognized
 * @n    exitph  -> save the calibrated parameters and exit from PH calibration mode
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Jiawei Zhang](jiawei.zhang@dfrobot.com)
 * @version  V1.0
 * @date  2018-11-06
 * @url https://github.com/DFRobot/DFRobot_PH
 */

#include "DFRobot_PH.h"
#include "DFRobot_EC.h"
#include <EEPROM.h>
#include <OneWire.h>

#define PH_PIN A1
#define EC_PIN A2

int DS18S20_Pin = 2; // DS18S20 Signal pin on digital 2

// Temperature chip i/o
OneWire ds(DS18S20_Pin); // on digital pin 2

float voltagePH, voltageEC, phValue, ecValue, temperature = 25;
DFRobot_PH ph;
DFRobot_EC ec;

void setup()
{
    Serial.begin(115200);
    ph.begin();
    ec.begin();
}

void loop()
{
    char cmd[10];
    static unsigned long timepoint = millis();
    if (millis() - timepoint > 1000U)
    { // time interval: 1s
        timepoint = millis();
        temperature = readTemperature();                // read your temperature sensor to execute temperature compensation
        voltagePH = analogRead(PH_PIN) / 1024.0 * 5000; // read the ph voltage
        phValue = ph.readPH(voltagePH, temperature);    // convert voltage to pH with temperature compensation
        Serial.print("pH:");
        Serial.print(phValue, 2);
        voltageEC = analogRead(EC_PIN) / 1024.0 * 5000;
        ecValue = ec.readEC(voltageEC, temperature); // convert voltage to EC with temperature compensation
        Serial.print(", EC:");
        Serial.print(ecValue, 2);
        Serial.println("ms/cm");
    }
    if (readSerial(cmd))
    {
        strupr(cmd);
        if (strstr(cmd, "PH"))
        {
            ph.calibration(voltagePH, temperature, cmd); // PH calibration process by Serail CMD
        }
        if (strstr(cmd, "EC"))
        {
            ec.calibration(voltageEC, temperature, cmd); // EC calibration process by Serail CMD
        }
    }
}

int i = 0;
bool readSerial(char result[])
{
    while (Serial.available() > 0)
    {
        char inChar = Serial.read();
        if (inChar == '\n')
        {
            result[i] = '\0';
            Serial.flush();
            i = 0;
            return true;
        }
        if (inChar != '\r')
        {
            result[i] = inChar;
            i++;
        }
        delay(1);
    }
    return false;
}

float readTemperature()
{
    // returns the temperature from one DS18S20 in DEG Celsius

    byte data[12];
    byte addr[8];

    if (!ds.search(addr))
    {
        // no more sensors on chain, reset search
        ds.reset_search();
        return -1000;
    }

    if (OneWire::crc8(addr, 7) != addr[7])
    {
        Serial.println("CRC is not valid!");
        return -1000;
    }

    if (addr[0] != 0x10 && addr[0] != 0x28)
    {
        Serial.print("Device is not recognized");
        return -1000;
    }

    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1); // start conversion, with parasite power on at the end

    byte present = ds.reset();
    ds.select(addr);
    ds.write(0xBE); // Read Scratchpad

    for (int i = 0; i < 9; i++)
    { // we need 9 bytes
        data[i] = ds.read();
    }

    ds.reset_search();

    byte MSB = data[1];
    byte LSB = data[0];

    float tempRead = ((MSB << 8) | LSB); // using two's compliment
    float TemperatureSum = tempRead / 16;

    return TemperatureSum;
}