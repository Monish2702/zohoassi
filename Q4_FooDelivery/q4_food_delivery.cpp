#include "foodDelivery.cpp"
static int order_count = 0;
int main()
{
    cout << "Available restraunts: \na-A2B\nb-Pascah\nt-Taj\ns-SS Hyderabad\ne-Elite" << endl;
    cout << "Available destinations: \na-Arumbakkam\nb-Besant nagar\nc-Chrompet\nd-Doveton\ne-Egmore" << endl;
    DeliveryExecutive executive[5];
    bool choice = true;

    while (choice)
    {
        int j = 0;
        cout << "\n---------\nDo you want to book a delivery?(y/n) :";
        char ch;
        cin >> ch;
        if (ch == 'y')
        {
            Orders order;
            ++order_count;
            // delivery_history.push_back(order);
            // find least delivery_charge_earned of out 5 delivery executives
            int minimun_delivery_charge = 2147483647, index = 0;
            for (int i = 0; i < 5; i++)
            {
                if (executive[i].delivery_charge_earned < minimun_delivery_charge)
                {
                    minimun_delivery_charge = executive[i].delivery_charge_earned;
                    index = i;
                }
            }
            cout << endl
                 << "Least earned is DE" << index + 1 << endl;
            //----------------------------------------------------------------------------------------------------------------------
            bool customer_id_checker = count(global_customers_id.begin(), global_customers_id.end(), order.customer_id);
            if(customer_id_checker) cout<<"\nCutomer id exists\n";
            bool flag = true;
            for (int i = 0; i < order_count; i++, j = (j + 1) % 5)
            {
                if (order_count == 1 && flag) // first order assigned to DE1
                {
                    executive[index].assign_delivery(order);
                    executive[index].assign_delivery_charge(50, 10);
                    global_customers_id.push_back(order.customer_id);
                    cout << "DE" << index + 1 << " gets this order" << endl; 
                    flag = false;
                }
                // clubbing orders that are for same locations within 15 mins
                else if ((flag) && (!customer_id_checker) && (abs(executive[j].orders_taken_by_delivery_executive[i].seconds - order.seconds) < 900) && (executive[j].orders_taken_by_delivery_executive[i].restaurant_name == order.restaurant_name) && (executive[j].orders_taken_by_delivery_executive[i].destination_name == order.destination_name))
                {
                    cout << "\nI'm in\n";
                    executive[j].assign_delivery(order);
                    executive[j].assign_delivery_charge(5, 0);
                    global_customers_id.push_back(order.customer_id);
                    cout << "DE" << j + 1 << " gets this order because of similarities"<< endl;
                    flag = false;
                }
                // order(unclubbed) assigned to DE with least earning
                else if (flag)
                {
                    executive[index].assign_delivery(order);
                    executive[index].assign_delivery_charge(50, 10);
                    global_customers_id.push_back(order.customer_id);
                    cout << "DE" << index + 1 << " gets this order" << endl;
                    flag = false;
                }
            }
        }
        else
        {
            choice = false;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "\n--------------------------------------------------------------------------------" << endl;
        cout << "DE" << i + 1 << endl;
        executive[i].display();
    }
}