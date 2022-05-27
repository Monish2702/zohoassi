// Run this file to execute the program
#include "q4_delivery_executive.cpp"

void book_and_assign_delivery_executive(DeliveryExecutive executive[], int no_of_persons, bool flag)
{
    Orders order;
    all_orders.push_back(order);
    order_count++;
    int minimun_delivery_charge = 2147483647, index = 0; // index - contains the index of the DE with least earnings
    cout << "\n----Available Executives----"
         << "\nExecutive\tDelivery charge earned\n";
    for (int i = 0; i < no_of_persons; i++)
    {
        cout << "DE" << i + 1 << "\t\t\t" << executive[i].delivery_charge_earned << "\n";
        if (executive[i].delivery_charge_earned < minimun_delivery_charge)
        {
            minimun_delivery_charge = executive[i].delivery_charge_earned;
            index = i;
        }
    }
    if (order_count == 1)
    {
        executive[index].assign_delivery(all_orders.back());
        executive[index].assign_delivery_charge(50, 10);
        executive[index].pickup_time = all_orders.back().seconds + 900;
        executive[index].delivery_time = all_orders.back().seconds + 1800;
        global_booking_id.push_back(order.booking_id);
        cout << endl
             << "Alloted Delivery executive: DE" << index + 1 << endl;
    }
    // assign the order to the delivery executive who has a previous order within 15 mins of this order or assign this order the delivery executive with least delivery charge earned
    else
    {
        bool booking_id_already_exists = count(global_booking_id.begin(), global_booking_id.end(), order.booking_id);
        for (int i = 0; i < 5; i++)
        {
            if (executive[i].orders_taken_by_delivery_executive.size() > 0)
            {
                for (int j = 0; j < executive[i].orders_taken_by_delivery_executive.size(); j++)
                {
                    //for clubbing orders to same executives
                    if (!booking_id_already_exists && abs(executive[i].orders_taken_by_delivery_executive[j].seconds - all_orders.back().seconds) <= 15 * 60 && executive[i].orders_taken_by_delivery_executive[j].restaurant_name == order.restaurant_name && executive[i].orders_taken_by_delivery_executive[j].destination_name == order.destination_name)
                    {
                        executive[i].assign_delivery(all_orders.back());
                        executive[i].assign_delivery_charge(5, 0);
                        executive[index].pickup_time = all_orders.back().seconds + 900;
                        executive[index].delivery_time = all_orders.back().seconds + 1800;
                        global_booking_id.push_back(order.booking_id);
                        cout << endl
                             << "Alloted Delivery executive: DE" << i + 1 << "(because same location within 15mins)" << endl;
                        flag = true;
                        break;
                    }
                    else if (!booking_id_already_exists)
                    {
                        continue;
                        // goto unclubbed;
                    }
                    break;
                }
            }
        }
    unclubbed:
        if (!flag)
        {
            executive[index].assign_delivery(all_orders.back());
            executive[index].assign_delivery_charge(50, 10);
            executive[index].pickup_time = all_orders.back().seconds + 900;
            executive[index].delivery_time = all_orders.back().seconds + 1800;
            global_booking_id.push_back(order.booking_id);
            cout << endl
                 << "Alloted Delivery executive: DE" << index + 1 << endl;
            return;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------
void display(DeliveryExecutive executive[], int no_of_persons)
{
    for (int i = 0; i < no_of_persons; i++)
    {
        cout << "\n--------------------------------------------------------------------------------" << endl;
        cout << "DE" << i + 1 << endl;
        executive[i].display();
    }
    cout << endl;
}

//---------------------------------------------------------------------------------------------------------------------------
int main()
{
    bool flag = false;
    cout << "Available restraunts: \na-A2B\nb-Pascah\nt-Taj\ns-SS Hyderabad\ne-Elite" << endl;
    cout << "Available destinations: \na-Arumbakkam\nb-Besant nagar\nc-Chrompet\nd-Doveton\ne-Egmore" << endl;
    DeliveryExecutive executive[5];
    int choice;
    do
    {
        cout << "\nEnter 1-booking 2-display 3-exit " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            book_and_assign_delivery_executive(executive, 5, flag);
            break;
        }
        case 2:
        {
            display(executive, 5);
            break;
        }
        case 3:
        {
            cout << "Exiting" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } while (choice != 3);
}