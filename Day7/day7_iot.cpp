#include <windows.h>

#include "day7_devices.h"

int main()
{
    
    bool exit = false;
    controller c;
    // cout<< "Enter current battery level : "<<endl;
    // cin>>c.battery_level;
    c.set_initial_conditions();
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