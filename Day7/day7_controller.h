#include "day7_devices.h"

vector<string> condition;
class controller
{
public:
    string command;
    int battery_level_to_turn_on_sensors, battery_level;
    void set_initial_conditions()
    {

        string s1, s2, word;
        cout << "\n Enter if: ";
        getline(cin >> ws, s1);
        cout << "\n Enter then: ";
        getline(cin >> ws, s2);
        cout << "\n-------------------\n";
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
                if (Temperature.sensor_temperature > stoi(condition[2]))
                    Fan.switch_on();
                else
                    Fan.switch_off();
            }
            else
            {
                cout << "Battery level is low" << endl;
                cout << "Do you want to charge the battery of temperature sensor? (y/n)" << endl;
                char ch;
                cin >> ch;
                if (ch == 'y')
                {
                    Gas.battery = 30;
                    cout << "Battery charged to 30%" << endl;
                }
            }
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
                if (Luminance.sensor_luminance < stoi(condition[7]))
                    Light.switch_on();
                else
                    Light.switch_off();
            }
            else
            {
                cout << "Battery level is low" << endl;
                cout << "Do you want to charge the battery of light? (y/n)" << endl;
                char ch;
                cin >> ch;
                if (ch == 'y')
                {
                    Gas.battery = 30;
                    cout << "Battery charged to 30%" << endl;
                }
            }
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
                cout << "Battery level is low" << endl;
                cout << "Do you want to charge the battery of motion sensor? (y/n)" << endl;
                char ch;
                cin >> ch;
                if (ch == 'y')
                {
                    Gas.battery = 30;
                    cout << "Battery charged to 30%" << endl;
                }
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
                if (Gas.gas_ppm > stoi(condition[12]))
                    Alarm.switch_on();
                else
                    Alarm.switch_off();
            }
            else
            {
                cout << "Battery level is low" << endl;
                cout << "Do you want to charge the battery of gas sensor? (y/n)" << endl;
                char ch;
                cin >> ch;
                if (ch == 'y')
                {
                    Gas.battery = 30;
                    cout << "Battery charged to 30%" << endl;
                }
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
                if (Water.water_level < stoi(condition[17]))
                    Pump.switch_on();
                else
                    Pump.switch_off();
            }
            else
            {
                cout << "Battery level is low" << endl;
                cout << "Do you want to charge the battery of water level sensor? (y/n)" << endl;
                char ch;
                cin >> ch;
                if (ch == 'y')
                {
                    Gas.battery = 30;
                    cout << "Battery charged to 30%" << endl;
                }
            }
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