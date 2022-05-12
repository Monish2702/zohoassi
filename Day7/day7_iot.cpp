#include <windows.h>
#include "day7_devices.h"

int main()
{
    bool exit = false;
    while (!exit)
    {
        cout << "Setting initial conditions..." << endl;
        float battery_level_to_turn_on_sensors = 15;
        float temperature_to_turn_on_fan = 25,luminance_to_turn_on_light = 100;
        
        
        float newTemperature, luminosity;
        bool are_you_present_in_proximity_of_sensor;
        float FanBatteryLevel, LightBatteryLevel, MotorBatteryLevel, water_level;
        cout << "\nSmart fans\n";
        cout << "Enter the temperature: ";
        cin >> newTemperature;
        cout << "Enter the Temperature sensor battery level: ";
        cin >> FanBatteryLevel;
        SmartFan fan(newTemperature, FanBatteryLevel);
        if (!fan.OnOff())
            fan.SwitchOffSesnor();

        cout << "\nSmart light\n";
        cout << "Enter the luminosity: ";
        cin >> luminosity;
        cout << "Enter the Luminous sensor battery level: ";
        cin >> LightBatteryLevel;
        SmartLight light(luminosity, LightBatteryLevel);
        if(!light.OnOff())
            light.SwitchOffSesnor();

        cout << "\nMotion control\n";
        cout << "Are you present in proximity of the sensor? (True/False): ";
        cin >> are_you_present_in_proximity_of_sensor;
        cout << "Enter the Proximity sensor battery level: ";
        cin >> MotorBatteryLevel;
        Motor motor(are_you_present_in_proximity_of_sensor, MotorBatteryLevel);
        if(!motor.OnOff())
            motor.SwitchOffSesnor();

        cout << "\nWater pump control\n";
        cout << "Enter water level in tank: ";
        cin >> water_level;
        cout << "Enter the Water sensor battery level: ";
        cin >> MotorBatteryLevel;
        WaterPump water_pump(water_level, MotorBatteryLevel);
        if(!water_pump.OnOff())
            water_pump.SwitchOffSesnor();
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            exit = true;
        }
    }
    return 0;
}