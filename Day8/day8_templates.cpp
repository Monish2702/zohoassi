#include <iostream>
#include <string>
#include <vector>
using namespace std;

class mobile
{
public:
    float bill_amount;
    char number[10];
    mobile()
    {
        bill_amount = 0;
    }
    void new_connection()
    {
        cout << "Enter mobile no: ";
        cin >> number;
    }
    void pay_bill(string number)
    {
        cout << "Your current due is: " << bill_amount << endl;
        cout << "Enter amount you are going to pay: ";
        float amount;
        cin >> amount;
        if (bill_amount >= amount)
        {
            bill_amount = bill_amount - amount;
            cout << "Bill amount remaining is: " << bill_amount << endl;
        }
        else
        {
            cout << "Entered amount is greater than you due amount" << endl;
        }
    }
    void update_bill(string number)
    {
        cout << "Enter new bill amount: ";
        float amount;
        cin >> amount;
        bill_amount = bill_amount + amount;
    }
};

class landline
{
public:
    float bill_amount;
    string number = "", landline_no, std_code = "";
    landline()
    {
        bill_amount = 0;
    }
    void new_connection()
    {
        cout << "Enter Landline no with std_code: ";
        cin >> landline_no;
        std_code += landline_no.substr(0, landline_no.length() - 6);
        number += landline_no.substr(landline_no.length() - 6, landline_no.length() - 1);
    }
    void pay_bill(string number)
    {
        cout << "Your current due is: " << bill_amount << endl;
        cout << "Enter amount you are going to pay: ";
        float amount;
        cin >> amount;
        if (bill_amount >= amount)
        {
            bill_amount = bill_amount - amount;
            cout << "Bill amount remaining is: " << bill_amount << endl;
        }
        else
        {
            cout << "Entered amount is greater than you due amount" << endl;
        }
    }
    void update_bill(string number)
    {
        cout << "Enter new bill amount: ";
        float amount;
        cin >> amount;
        bill_amount = bill_amount + amount;
    }
};

template <typename T>

class bill_payments
{
public:
    vector<T> bill_details;
    bill_payments() {}
    void new_connection()
    {
        T tempo;
        tempo.new_connection();
        bill_details.push_back(tempo);
        cout << "No of connections with us is : " << bill_details.size() << endl;
    }

    void pay_bill(string number)
    {
        for (int i = 0; i < bill_details.size(); i++)
        {
            if (bill_details[i].number == number)
            {
                bill_details[i].pay_bill(number);
            }
        }
    }

    void update_bill(string number)
    {
        for (int i = 0; i < bill_details.size(); i++)
        {
            if (bill_details[i].number == number)
            {
                bill_details[i].update_bill(number);
            }
        }
    }

    bool number_exist(string number)
    {
        for (int i = 0; i < bill_details.size(); i++)
        {
            if (bill_details[i].number == number)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    bill_payments<mobile> m;
    bill_payments<landline> l;
    int choice;
    do
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice: " << endl;
        cout << "0-Exit\n1-Add new mobile connection\n2-Add new landline connection" << endl;
        cout << "3-Pay bill using connection number\n4-Update bill amount using connection number" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            m.new_connection();
            break;
        }
        case 2:
        {

            l.new_connection();
            break;
        }
        case 3:
        {
            cout << "Enter Connection number whose bill you want to pay: ";
            string number;
            cin >> number;
            if (m.number_exist(number) || l.number_exist(number))
            {
                if (number.length() == 10)
                {

                    m.pay_bill(number);
                }
                else if (number.length() == 9)
                {

                    l.pay_bill(number);
                }
                else
                {
                    cout << "Invalid connection number" << endl;
                }
            }
            else
            {
                cout << "Connection number does not exist" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Enter Connection number whose bill amount you want to update: ";
            string number;
            cin >> number;
            if (m.number_exist(number) || l.number_exist(number))
            {
                if (number.length() == 10)
                {
                    m.update_bill(number);
                }
                else if (number.length() == 9)
                {

                    l.update_bill(number);
                }
                else
                {
                    cout << "Invalid connection number" << endl;
                }
            }
            else
            {
                cout << "Connection number does not exist" << endl;
            }
        }
        default:
            break;
        }
    } while (choice != 0);
    cout << "--------------------------------------------------------------------------------" << endl;
    return 0;
}
