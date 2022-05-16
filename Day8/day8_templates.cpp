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
    void display()
    {
        cout << "Mobile no: " << number << endl;
        cout << endl;
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
    void display()
    {
        cout << "Landline no: " << number << endl;
        cout << "STD code: " << std_code << endl;
        cout << endl;
    }
};

template <typename T>

class bill_payments
{
public:
    vector<T> bill_details;
    bill_payments() {}
    T tempo;
    void display()
    {
        tempo.display();
    }

    void new_connection()
    {
        tempo.new_connection();
        bill_details.push_back(tempo);
        cout << " No of connections with us is : " << bill_details.size() << endl;
    }

    void pay_bill(string number)
    {
        tempo.pay_bill(number);
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
        cout << "--------------------------------------------------------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            m.new_connection();
            m.display();
            break;
        }
        case 2:
        {

            l.new_connection();
            l.display();
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
                    m.tempo.bill_amount = 0;
                    cout << "Enter new bill amount: ";
                    float amount;
                    cin >> amount;
                    m.tempo.bill_amount = m.tempo.bill_amount + amount;
                    m.display();
                }
                else if (number.length() == 9)
                {
                    l.tempo.bill_amount = 0;
                    cout << "Enter new bill amount: ";
                    float amount;
                    cin >> amount;
                    l.tempo.bill_amount = l.tempo.bill_amount + amount;
                    l.display();
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
    return 0;
}
