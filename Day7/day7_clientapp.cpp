#include "day7_controller.h"

int main()
{
    int i = 0;
    bool exit = false;
    controller c;
    cout << "Enter battery level to turn on sensors: ";
    cin >> c.battery_level_to_turn_on_sensors;
    cout << "Enter the conditions(in order of temperature, luminance, gas, water):"
         << "\n<sensor_name> <operator> <value>\n <device_name> <function>" << endl;
    while (i < 4)
    {
        c.set_initial_conditions();
        ++i;
    }
    cout << "\nInitial conditions set..." << endl;
    cout << "Starting program..." << endl;
    cout << "Press 'ESC' to exit program" << endl;
    cout << "\n";
    while (!exit)
    {
        c.sensing();
        c.onBatteryLevelChange(c.battery_level_to_turn_on_sensors);
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            exit = true;
        }
    }
    return 0;
}