#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> global_booking_id;
class Orders
{
public:
    int customer_id, hrs, mins, seconds;
    string restaurant_name, destination_name, am_pm, input_time;
    static int booking_id;
    // bool flag;
    Orders() // constructor to set place the orders
    {
        ++booking_id;
        // flag = true;
        cout << "\nEnter customer id: ";
        cin >> customer_id;
        cout << "\nEnter restraunt name: ";
        getline(cin >>ws, restaurant_name);
        cout << "\nEnter destination name: ";
        getline(cin >>ws, destination_name);
        cout << "\nEnter time (hh.mm.AM_PM): ";

        getline(cin >> ws, input_time);
        hrs = stoi(input_time.substr(0, 2));
        mins = stoi(input_time.substr(3, 2));
        am_pm = input_time.substr(6, 2);

        if (am_pm == "AM")
            seconds = hrs * 60 * 60 + mins * 60;
        else if (am_pm == "PM")
            seconds = (hrs + 12) * 60 * 60 + mins * 60;
        else
            cout << endl
                 << "Please enter AM or PM only";
        cout << endl
             << "Booking ID: " << booking_id << endl;
    }
    void display() // just to display
    {
        cout << "\nCustomer id\tRestraunt name\tDestination name\tOrdered time" << endl;
        cout << customer_id << "\t\t" << restaurant_name << "\t\t" << destination_name << "\t\t\t" << hrs << ":" << mins << ":" << am_pm;
    }
};
vector<Orders> all_orders;
int Orders::booking_id = 0;
