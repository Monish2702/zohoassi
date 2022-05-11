#include <iostream>
#include <string>
#include <vector>
using namespace std;
class broker; // forward declaration
// Base classes bank,loan
class bankDetails
{
public:
    string bankName, establishedDate, bankType, branch;
    virtual string getName() = 0;
    virtual string getEstablishedDate() = 0;
    virtual string getBankType() = 0;
    virtual string getBranch() = 0;
    void getInfo()
    {
        cout << endl
             << "Bank Name: " << bankName << endl;
        cout << "Established Date: " << establishedDate << endl;
        cout << "Bank Type: " << bankType << endl
             << endl;
        cout << "Bank Branch: " << branch << endl;
    }
};

class loan
{
public:
    string loanType, docsrequired;
    float interestRate;
    // friend class compare; //friend class
    string getLoanType() { return loanType; }
    string getDocsRequired() { return docsrequired; }
    float getInterestRate() { return interestRate; }
};

//---------------------------------------------------------------------------------------------------------------------
class BANK : public bankDetails, public loan
{
public:
    friend class broker;
    BANK()
    {

        cout << "\nEnter the name of the bank: ";
        cin >> bankName;
        cout << endl;

        cout << "Enter the established date of the bank: ";
        cin >> establishedDate;
        cout << endl;

        cout << "Enter the type of the bank: ";
        cin >> bankType;
        cout << endl;

        cout << "Enter the Types of the loan available: ";
        cin >> loanType;
        cout << endl;

        cout << "Enter the docs required for the loan: ";
        cin >> docsrequired;
        cout << endl;

        cout << "Enter the bank branch: ";
        cin >> branch;
        cout << endl;

        cout << "Enter the interest rate of the loan: ";
        cin >> interestRate;
        cout << endl;
    }

    string getName()
    {
        return bankName;
    }
    string getEstablishedDate()
    {
        return establishedDate;
    }
    string getBankType()
    {
        return bankType;
    }
    string getBranch()
    {
        return branch;
    }
};
//-----------------------------------------------------------------------------------------------------------------------------

class broker
{
public:
    // compare interest Rates of 2 banks
    void compareInterestRate(BANK b1, BANK b2)
    {
        b1.interestRate < b2.interestRate ? cout << "Bank with Lowest interest is: " << b1.bankName << endl : cout << "Bank with Lowest interest is: " << b2.bankName << endl;
    }
    // compare interest Rates of 3 banks
    void compareInterestRate(BANK b1, BANK b2, BANK b3)
    {
        b1.interestRate < b2.interestRate ? cout << "Bank with Lowest interest is: " << b1.bankName << endl : b2.interestRate < b3.interestRate ? cout << "Bank with Lowest interest is: " << b2.bankName << endl
                                                                                                                                                : cout << "Bank with Lowest interest is: " << b3.bankName << endl;
    }

    // compare interest Rates of n banks
    void compareInterestRate(BANK a[], int n)
    {
        float min = a[0].interestRate;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].interestRate < min)
            {
                min = a[i].interestRate;
                index = i;
            }
        }
        cout << "The bank with the lowest interest rate is: " << a[index].bankName << endl;
        cout << "The interest rate is: " << min << endl;
    }
    // print all details of the bank
    void printSinglebankdata(BANK a)
    {
        cout << "\nBank Name: " << a.bankName << endl;
        cout << "Established Date: " << a.establishedDate << endl;
        cout << "Bank Type: " << a.bankType << endl;
        cout << "Bank Branch: " << a.branch << endl;
        cout << "Loan Type: " << a.loanType << endl;
        cout << "Docs Required: " << a.docsrequired << endl;
        cout << "Interest Rate: " << a.interestRate << endl;
    }
    // print all details of multiple banks
    void printMultiplebankdata(BANK a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nBank Name: " << a[i].bankName << endl;
            cout << "Established Date: " << a[i].establishedDate << endl;
            cout << "Bank Type: " << a[i].bankType << endl;
            cout << "Bank Branch: " << a[i].branch << endl;
            cout << "Loan Type: " << a[i].loanType << endl;
            cout << "Docs Required: " << a[i].docsrequired << endl;
            cout << "Interest Rate: " << a[i].interestRate << endl;
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
    BANK *b = new BANK[n];
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
    // broker class methods zone
    broker c;
    if (n > 2)
    {
        cout << "\nComparing two banks:\n ";
        c.compareInterestRate(b[0], b[1]);
        cout << "\nComparing three banks:\n ";
        c.compareInterestRate(b[0], b[1], b[2]);
    }
    cout << "----------------\n This can compare n banks:\n ";
    c.compareInterestRate(b, n); // multiple banks comparison
    cout << "\nPrinting all details of the bank:\n ";
    c.printMultiplebankdata(b, n);
    int x;
    cout << "\nEnter the bank's number to be printed: ";
    cin >> x;
    cout << "\nPrinting all details of " << x << " bank:\n ";
    c.printSinglebankdata(b[x - 1]);

    return 0;
}