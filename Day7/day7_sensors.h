#include <iostream>
using namespace std;
// using std::cin;
// using std::cout;
// using std::endl;
// using std::string;
// using std::vector;
// //Parent class
class Devices
{
public:
    // float sTemperature,sLuminance,sWater,sGas;
    bool OnOffStatus,sMotion;
    int newBatteryLevel;
    int battery;
    Devices() 
    {
        battery = 25;
    }
    bool OnConnect()
    {
        OnOffStatus = true;
        return OnOffStatus;
    }

    bool OnDisconnect()
    {
        OnOffStatus = false;
        return OnOffStatus;
    }

    int onBatteryLevelChange(int newBatteryLevel)
    {
        this->newBatteryLevel = newBatteryLevel;
        return newBatteryLevel;
    }
};

// Sensor 1) Temperature
class TemperatureSensor : public Devices
{
public:
    float sensor_temperature;
    // int newBatteryLevel;
    TemperatureSensor()
    {
        OnConnect();
        battery=30;
        sensor_temperature=25;
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float onTemperatureChange(bool increase)
    {
        if(increase)
            ++sensor_temperature;
        else 
           --sensor_temperature;
        cout<<"Temperature: "<<sensor_temperature<<endl;
        return sensor_temperature;
    }
};

// Sensor 2) Luminance
class LuminanceSensor : public Devices
{
public:
    float sensor_luminance;
    LuminanceSensor()
    {
        OnConnect();
        battery=30;
        sensor_luminance=25;
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float onLuminanceChange(bool increase)
    {
        if(increase)
            ++sensor_luminance;
        else 
           --sensor_luminance;
        cout<<"Temperature: "<<sensor_luminance<<endl;
        return sensor_luminance;
    }

};

// Sensor 3) Motion(proximity)
class MotionSensor : public Devices
{
public:
    bool sensor_motion;
    MotionSensor()
    {
        OnConnect();
        battery=30;
        sensor_motion = false;
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float onMotionChange(bool newMotion)
    {
        if(sensor_motion)
            sensor_motion = true;
        else 
            sensor_motion = false;
        cout<<"Motion: "<<sensor_motion<<endl;
    }
};

class WaterLevelSensor : public Devices
{
public:
    int water_level;
    WaterLevelSensor()
    {
        OnConnect();
        battery=30;
        water_level = 50;
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float OnWaterLevelChange(bool newWater)
    {
        if(newWater)
            ++water_level;
        else 
            --water_level;
        cout<<"Water Level: "<<water_level<<endl;
        return water_level;
    }
};

class GasDetectionsSensor : public Devices
{
public:
    int gas_ppm;
    GasDetectionsSensor()
    {
        OnConnect();
        battery=30;
        gas_ppm=25;
    }
    int battery = onBatteryLevelChange(newBatteryLevel);
    float onGasChange(bool newGas)
    {
        if(newGas)
            ++gas_ppm;  
        else 
            --gas_ppm;
        cout<<"Gas: "<<gas_ppm<<endl;
        return gas_ppm;
    }
};

// Actuator 1) Smart Fan
class SmartFan : public Devices
{
public:
    void switch_on()
    {
    cout<<"Fan is :"<<OnConnect()<<endl;
    }
    void switch_off()
    {
    cout<<"Fan is :"<<OnDisconnect()<<endl;
    }
};

// Actuator 2) Smart Light
class SmartLight : public Devices
{
public:
    void switch_on()
    {
    cout<<"Light is :"<<OnConnect()<<endl;
    }
    void switch_off()
    {
    cout<<"Light is :"<<OnDisconnect()<<endl;
    }

};

// Actuator 3) Door
class Door : public Devices // door control
{
public:
    void openDoor()
    {
    cout<<"Door is :"<<OnConnect()<<endl;
    }
    void closeDoor()
    {
    cout<<"Door is :"<<OnDisconnect()<<endl;
    }
};

// Actuator 4) Pump
class WaterPump : public Devices
{
public:
    void switch_on()
    {
    cout<<"Pump is :"<<OnConnect()<<endl;
    }
    void switch_off()
    {
    cout<<"Pump is :"<<OnDisconnect()<<endl;
    }
};

class GasAlarm : public Devices
{  // gas alarm
public:
    void switch_on()
    {
    cout<<"Gas alarm is :"<<OnConnect()<<endl;
    }
    void switch_off()
    {
    cout<<"Gas alarm is :"<<OnDisconnect()<<endl;
    }
};