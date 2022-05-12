#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Broker; // forward declaration
// Base classes bank,loan
class BankDetails
{
public:
    string bank_name, established_date, branch;
    bool bank_type;
    virtual string getName() = 0;
    virtual string getEstablishedDate() = 0;
    virtual bool getBankType() = 0;
    virtual string getBranch() = 0;
    void getInfo()
    {
        cout << endl
             << "Bank Name: " << bank_name << endl;
        cout << "Established Date: " << established_date << endl;
        cout << "Bank Type: " << bank_type << endl
             << endl;
        cout << "Bank Branch: " << branch << endl;
    }
};

class Loan
{
public:
    string loan_type, docs_required;
    float interest_rate;
    // friend class compare; //friend class
    string getLoanType() { return loan_type; }
    string getDocsRequired() { return docs_required; }
    float getInterestRate() { return interest_rate; }
};

//---------------------------------------------------------------------------------------------------------------------
class Bank : public BankDetails, public Loan
{
public:
    friend class Broker;
    Bank()
    {

        cout << "\nEnter the name of the bank: ";
        cin >> bank_name;
        cout << endl;

        cout << "Enter the established date of the bank: ";
        cin >> established_date;
        cout << endl;

        cout << "Enter the type of the bank: ";
        cin >> bank_type;
        cout << endl;

        cout << "Enter the Types of the loan available: ";
        cin >> loan_type;
        cout << endl;

        cout << "Enter the docs required for the loan: ";
        cin >> docs_required;
        cout << endl;

        cout << "Enter the bank branch: ";
        cin >> branch;
        cout << endl;

        cout << "Enter the interest rate of the loan: ";
        cin >> interest_rate;
        cout << endl;
    }

    string getName()
    {
        return bank_name;
    }
    string getEstablishedDate()
    {
        return established_date;
    }
    bool getBankType()
    {
        return bank_type;
    }
    string getBranch()
    {
        return branch;
    }
};
//-----------------------------------------------------------------------------------------------------------------------------

class Broker
{
public:
    // compare interest Rates of 2 banks
    void CompareInterestRate(Bank b1, Bank b2)
    {
        b1.interest_rate < b2.interest_rate ? cout << "Bank with Lowest interest is: " << b1.bank_name << endl : cout << "Bank with Lowest interest is: " << b2.bank_name << endl;
    }
    // compare interest Rates of 3 banks
    void CompareInterestRate(Bank b1, Bank b2, Bank b3)
    {
        b1.interest_rate < b2.interest_rate ? cout << "Bank with Lowest interest is: " << b1.bank_name << endl : b2.interest_rate < b3.interest_rate ? cout << "Bank with Lowest interest is: " << b2.bank_name << endl
                                                                                                                                                     : cout << "Bank with Lowest interest is: " << b3.bank_name << endl;
    }

    // compare interest Rates of n banks
    void CompareInterestRate(Bank a[], int n)
    {
        float min = a[0].interest_rate;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].interest_rate < min)
            {
                min = a[i].interest_rate;
                index = i;
            }
        }
        cout << "The bank with the lowest interest rate is: " << a[index].bank_name << endl;
        cout << "The interest rate is: " << min << endl;
    }
    // print all details of the bank
    void PrintSinglebankdata(Bank a)
    {
        cout << "\nBank Name: " << a.bank_name << endl;
        cout << "Established Date: " << a.established_date << endl;
        cout << "Bank Type: " << a.bank_type << endl;
        cout << "Bank Branch: " << a.branch << endl;
        cout << "Loan Type: " << a.loan_type << endl;
        cout << "Docs Required: " << a.docs_required << endl;
        cout << "Interest Rate: " << a.interest_rate << endl;
    }
    // print all details of multiple banks
    void PrintMultiplebankdata(Bank a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nBank Name: " << a[i].bank_name << endl;
            cout << "Established Date: " << a[i].established_date << endl;
            cout << "Bank Type: " << a[i].bank_type << endl;
            cout << "Bank Branch: " << a[i].branch << endl;
            cout << "Loan Type: " << a[i].loan_type << endl;
            cout << "Docs Required: " << a[i].docs_required << endl;
            cout << "Interest Rate: " << a[i].interest_rate << endl;
        }
    }
};

//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------

int main()
{
    int n;
    cout << "Enter No of banks : ";
    cin >> n;
    Bank *b = new Bank[n];
    for (int i = 0; i != n; i++)
    {
        cout << endl
             << "Details of bank " << i + 1 << endl;
        cout << b[i].getName();
        cout << endl;
        cout << b[i].getEstablishedDate();
        cout << endl;
        cout << b[i].getBankType();
        cout << endl;
        cout << b[i].getBranch();
        cout << endl;
        cout << b[i].getLoanType();
        cout << endl;
        cout << b[i].getInterestRate();
        cout << endl;
        cout << b[i].getDocsRequired();
        cout << endl;
        b[i].getInfo();
        cout << endl;
        cout << '\n';
    }
    // Broker class methods zone
    Broker c;
    if (n > 2)
    {
        cout << "\nComparing two banks:\n ";
        c.CompareInterestRate(b[0], b[1]);
        cout << "\nComparing three banks:\n ";
        c.CompareInterestRate(b[0], b[1], b[2]);
    }
    cout << "----------------\n This can compare n banks:\n ";
    c.CompareInterestRate(b, n); // multiple banks comparison
    cout << "\nPrinting all details of the bank:\n ";
    c.PrintMultiplebankdata(b, n);
    int x;
    cout << "\nEnter the bank's number to be printed: ";
    cin >> x;
    cout << "\nPrinting all details of " << x << " bank:\n ";
    c.PrintSinglebankdata(b[x - 1]);

    return 0;
}