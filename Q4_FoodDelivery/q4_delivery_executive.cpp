#include "q4_order_class.cpp"
class DeliveryExecutive // to be done
{
public:
    int name;
    int delivery_charge_earned, allowance_earned;
    int pickup_time, delivery_time;
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

        cout << "\nORDERS TAKEN BY DELIVERY EXECUTIVE: ";
        for (int i = 0; i < orders_taken_by_delivery_executive.size(); i++)
        {
            cout << "\n\t";
            cout << "\nPickup time: " << pickup_time / 3600 << ":" << (pickup_time % 3600) / 60;
            cout << "\nDelivery time: " << delivery_time / 3600 << ":" << (delivery_time % 3600) / 60 << endl;
            orders_taken_by_delivery_executive[i].display();
        }
    }
};

static int order_count = 0;