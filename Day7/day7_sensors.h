#include <iostream>

//Parent class
class Events
{
public:
    float sTemperature,sLuminance,sWater,sGas;
    bool OnOffStatus,sMotion;
    int newBatteryLevel;

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
    void SwitchOffSesnor()
    {
        OnDisconnect();
        std::cout<< "Disconnected due to low battery" << std::endl;
    }
};

// Sensor 1) Temperature
class TemperatureSensor : public Events
{
public:
    // float newTemperature;
    // int newBatteryLevel;
    TemperatureSensor()
    {
        OnConnect();
    }

    // int battery = onBatteryLevelChange(newBatteryLevel);
    float onTemperatureChange(float newTemperature)
    {
        sTemperature = newTemperature;
        return sTemperature;
        // OnTemperatureChange();
    }
    // bool on()
    // {
    //     OnOffStatus = true;
    //     return OnOffStatus;
    // }
    
};

// Sensor 2) Luminance
class LuminanceSensor : public Events
{
public:
    LuminanceSensor()
    {
        OnConnect();
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float onLuminanceChange(float newLuminance)
    {
        sLuminance = newLuminance;
        return sLuminance;
        // OnTemperatureChange();
    }
    bool on()
    {
        OnOffStatus = true;
        return OnOffStatus;
    }
};


// Sensor 3) Motion(proximity)
class MotionSensor : public Events
{
public:
    MotionSensor()
    {
        OnConnect();
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float OnMotionChange(float newMotion)
    {
        sMotion = newMotion;
        return sMotion;
        // onMotionChange();
    }
    bool on()
    {
        OnOffStatus = true;
        return OnOffStatus;
    }
};

class WaterLevelSensor : public Events
{
public:
    WaterLevelSensor()
    {
        OnConnect();
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float OnWaterLevelChange(float newWater)
    {
        sWater = newWater;
        return sWater;
        // onWaterChange();
    }
    bool on()
    {
        OnOffStatus = true;
        return OnOffStatus;
    }
};

class GasDetectionsSensor : public Events
{
public:
    GasDetectionsSensor()
    {
        OnConnect();
    }

    int battery = onBatteryLevelChange(newBatteryLevel);
    float onGasChange(float newGas)
    {
        sGas = newGas;
        return sGas;
        // onGasChange();
    }
    bool on()
    {
        OnOffStatus = true;
        return OnOffStatus;
    }
};