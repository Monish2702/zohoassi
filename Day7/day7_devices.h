#include "day7_sensors.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
vector<string> condition;
class controller
{
public:
    string command;
    int battery_level_to_turn_on_sensors, battery_level;
    int temperature_to_turn_on_fan, luminance_to_turn_on_light, height_to_turn_on_water_pump, ppm_to_turn_on_gas_pump;
    // Devices D;
    // D.battery_level= battery_level;
    void set_initial_conditions()
    {
        string s1, s2, word;
        cout << "\n Enter if stmt: ";
        getline(cin >> ws, s1);
        cout << "\n Enter then stmt: ";
        getline(cin >> ws, s2);
        stringstream ss1(s1);
        while (ss1 >> word)
        {
            condition.push_back(word);
        }
        stringstream ss2(s2);

        while (ss2 >> word)
        {
            condition.push_back(word);
        }
        // cout << "Enter battery level to turn on sensors: ";
        // cin >> battery_level_to_turn_on_sensors;
        // cout << "Enter temperature to turn on fan: ";
        // cin >> temperature_to_turn_on_fan;
        // cout << "Enter luminance to turn on light: ";
        // cin >> luminance_to_turn_on_light;
        // cout << "Enter height to turn on water pump: ";
        // cin >> height_to_turn_on_water_pump;
        // cout << "Enter ppm to turn on gas pump: ";
        // cin >> ppm_to_turn_on_gas_pump;
        // cout << "Initial conditions set..." << endl;
        // cout << "Starting program..." << endl;
        // cout << "Press 'ESC' to exit program" << endl;
        // cout << "\n";
    }

    TemperatureSensor Temperature;
    LuminanceSensor Luminance;
    MotionSensor Motion;
    GasDetectionsSensor Gas;
    WaterLevelSensor Water;
    SmartFan Fan;
    SmartLight Light;
    Door Door;
    WaterPump Pump;
    GasAlarm Alarm;
    // Gas.battery = battery_level_to_turn_on_sensors;
    void sensing()
    {
        cin >> command;
        // temperature-fan
        if (command[0] == 't')
        {
            --Temperature.battery;
            if (Temperature.battery > battery_level_to_turn_on_sensors)
            {
                if (command[1] == 'i')
                    Temperature.onTemperatureChange(1);
                else if (command[1] == 'd')
                    Temperature.onTemperatureChange(0);
                if (Temperature.sensor_temperature > temperature_to_turn_on_fan)
                    Fan.switch_on();
                else
                    Fan.switch_off();
            }
            else
                cout << "Battery level is low, please charge the battery" << endl;
        }
        // luminance-light
        else if (command[0] == 'l')
        {
            --Luminance.battery;
            if (Luminance.battery > battery_level_to_turn_on_sensors)
            {
                if (command[1] == 'i')
                    Luminance.onLuminanceChange(1);
                else if (command[1] == 'd')
                    Luminance.onLuminanceChange(0);
                if (Luminance.sensor_luminance > luminance_to_turn_on_light)
                    Light.switch_on();
                else
                    Light.switch_off();
            }
            else
                cout << "Battery level is low, please charge the battery" << endl;
        }
        // motion-door
        else if (command[0] == 'd')
        {
            --Motion.battery;
            if (Motion.battery > battery_level_to_turn_on_sensors)
            {
                if (command[1] == 'o')
                    Door.openDoor();
                else if (command[1] == 'c')
                    Door.closeDoor();
            }
            else
            {
                cout << "Battery level is low, please charge the battery" << endl;
            }
        }
        // gas-alarm
        else if (command[0] == 'g')
        {
            --Gas.battery;
            if (Gas.battery > battery_level_to_turn_on_sensors)
            {
                if (command[1] == 'i')
                    Gas.onGasChange(1);
                else if (command[1] == 'd')
                    Gas.onGasChange(0);
                if (Gas.gas_ppm > ppm_to_turn_on_gas_pump)
                    Alarm.switch_on();
                else
                    Alarm.switch_off();
            }
            else
            {
                cout << "Battery level is low, please charge the battery" << endl;
            }
        }
        // water-pump
        else if (command[0] == 'w')
        {
            --Water.battery;
            if (Water.battery > battery_level_to_turn_on_sensors)
            {
                if (command[1] == 'i')
                    Water.OnWaterLevelChange(1);
                else if (command[1] == 'd')
                    Water.OnWaterLevelChange(0);
                if (Water.water_level > height_to_turn_on_water_pump)
                    Pump.switch_on();
                else
                    Pump.switch_off();
            }
            else
                cout << "Battery level is low, please charge the battery" << endl;
        }
    }

    void onBatteryLevelChange(int newBatteryLevel)
    {
        Fan.onBatteryLevelChange(newBatteryLevel);
        Fan.onBatteryLevelChange(newBatteryLevel);
        Light.onBatteryLevelChange(newBatteryLevel);
        Door.onBatteryLevelChange(newBatteryLevel);
        Pump.onBatteryLevelChange(newBatteryLevel);
        Gas.onBatteryLevelChange(newBatteryLevel);
    }
};