#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
vector <int> global_customers_id;
class Orders
{
public:
    int customer_id, hrs, mins, seconds;
    string restaurant_name, destination_name;
    char am_pm;

    Orders() // constructor to set place the orders
    {
        cout << "\nEnter customer id: ";
        cin >> customer_id;
        cout << "\nEnter restraunt name: ";
        cin >> restaurant_name;
        cout << "\nEnter destination name: ";
        cin >> destination_name;
        cout << "\nEnter time: ";
        cin >> hrs >> mins >> am_pm;
        if (am_pm == 'a')
            seconds = hrs * 60 * 60 + mins * 60;
        else if (am_pm == 'p')
            seconds = (hrs + 12) * 60 * 60 + mins * 60;
        else
            cout << "\nPlease enter a or p only";
    }
    void display() // just to display
    {
        cout << "\nCustomer id: " << customer_id;
        cout << "\nRestraunt name: " << restaurant_name;
        cout << "\nDestination name: " << destination_name;
        cout << "\nTime: " << hrs << ":" << mins << ":" << am_pm;
        cout << "\nTotal time: " << seconds;
    }
};

// vector<Orders> delivery_history;

class DeliveryExecutive // to be done
{
public:
    int name;
    int delivery_charge_earned, allowance_earned;
    vector<Orders> orders_taken_by_delivery_executive;

    DeliveryExecutive()
    {
        delivery_charge_earned = allowance_earned = 0;
    }
    void assign_delivery(Orders &delivery)
    {
        orders_taken_by_delivery_executive.push_back(delivery);
    }
    void assign_delivery_charge(int del_charge, int allowance)
    {
        delivery_charge_earned += del_charge;
        allowance_earned += allowance;
    }
    void display()
    {
        cout << "\nDelivery charge earned: " << delivery_charge_earned;
        cout << "\nAllowance earned: " << allowance_earned;
        cout << "\nOrders taken by delivery executive: ";
        for (int i = 0; i < orders_taken_by_delivery_executive.size(); i++)
        {
            cout << "\n\t";
            orders_taken_by_delivery_executive[i].display();
        }
    }
};

