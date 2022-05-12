#include "day7_sensors.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;


// Actuator 1) Smart Fan
class SmartFan : public TemperatureSensor
{
public:
    float newTemperature;
    int newBatteryLevel;
    SmartFan(float newTemperature, int newBatteryLevel)
    {
        this->newTemperature = newTemperature;
        this->newBatteryLevel = newBatteryLevel;
        OnConnect();
        onTemperatureChange(newTemperature);
    }
    bool OnOff()
    {
        if(newBatteryLevel > 15)
        {
        if (sTemperature > 15)
        {
            cout << "Fan is : " << OnConnect() << endl;
        }
        else
        {
            cout << "Fan is :" << OnDisconnect() << endl;
        }
        }
        else
        { 
            return false;
            cout << "Battery is low" << endl;
        }
    }
    ~SmartFan(){}
};






// Actuator 2) Smart Light
class SmartLight : public LuminanceSensor
{   
public:
    float newLuminance;
    int newBatteryLevel;
    SmartLight(float newLuminance, int newBatteryLevel)
    {
        this->newLuminance = newLuminance;
        this->newBatteryLevel = newBatteryLevel;
        OnConnect();
        onLuminanceChange(newLuminance);
    }
    bool OnOff()
    {
        if(battery > 15)
        {
        if (sLuminance > 25)
        {
            cout << "Light is : " << OnConnect() << endl;
        }
        else
        {
            cout << "Light is :" << OnDisconnect() << endl;
        }
        }
        else
        { 
            return false;
            cout << "Battery is low" << endl;
        }
    }
};











// Actuator 3) Motor
class Motor : public MotionSensor //door control
{
public:
    int newBatteryLevel; bool isPresent;
    Motor(bool isPresent, int newBatteryLevel)
    {
        this->isPresent = isPresent;
        this->newBatteryLevel = newBatteryLevel;
        OnConnect();
        OnMotionChange(isPresent);
    }
    bool OnOff()
    {
        if(battery > 15)
        {
        if (isPresent)
        {
            cout << "Motor is : " << OnConnect() << endl;
        }
        else
        {
            cout << "Motor is :" << OnDisconnect() << endl;
        }
        }
        else
        { 
            return false;
            cout << "Battery is low" << endl;
        }
    }
};





// Actuator 4) Pump
class WaterPump : public WaterLevelSensor
{  
public:
    int newBatteryLevel;
    float newWaterLevel;
    WaterPump(float newWaterLevel, float newBatteryLevel)
    {
        this->newBatteryLevel = newBatteryLevel;
        this->newWaterLevel = newWaterLevel;
        OnConnect();
        OnWaterLevelChange(newWaterLevel);
    }
    int battery = onBatteryLevelChange(newBatteryLevel);
    bool OnOff()
    {
        if(battery > 15)
        {
        if (sWater<50)
        {
            cout << "Water Pump is : " << OnConnect() << endl;
        }
        else
        {
            cout << "Water Pump is :" << OnDisconnect() << endl;
        }
        }
        else
        { 
            return false;
            cout << "Battery is low" << endl;
        }
    }
};
