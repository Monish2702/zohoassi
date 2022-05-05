#include<iostream>
#include<string>
#include<vector>
using namespace std;
class compare; //forward declaration
//Base classes bank,loan
class bank{public:
    string bankName,establishedDate,bankType;
    void getName(){
        cout<<"Enter the name of the bank: ";
        getline(cin,bankName);cout<<endl;
    }
    void getEstablishedDate(){
        cout<<"Enter the established date of the bank: ";
        getline(cin,establishedDate); cout<<endl;
    }
    void getBankType(){
        cout<<"Enter the type of the bank: ";
        getline(cin,bankType); cout<<endl;
    }
    void getInfo(){
        cout<<endl<<"Bank Name: "<<bankName<<endl;
        cout<<"Established Date: "<<establishedDate<<endl;
        cout<<"Bank Type: "<<bankType<<endl<<endl;
    }
};

class loan{public:
    string loanType,docsrequired;
    float interestRate;
    // friend class compare; //friend class
    void getLoanType(){
        cout<<"Enter the Types of the loan available: ";
        getline(cin, loanType);
    }
    void getDocsRequired(){
        cout<<"Enter the docs required for the loan: ";
        getline(cin, docsrequired);
    }
    void getInterestRate(){
        cout<<"Enter the interest rate of the loan: ";
        cin>>interestRate;
    }
};

//---------------------------------------------------------------------------------------------------------------------
class HDFC:public bank,public loan{public:
    void getName(){
        bank::getName();
    }
    void getEstablishedDate(){
        bank::getEstablishedDate();
    }
    void getBankType(){
        bank::getBankType();
    }
    void getInfo(){
        bank::getInfo();
    }
}; 
//---------------------------------------------------------------------------------------------------------------------
class SBI:public bank,public loan{public:
    void getName(){
        bank::getName();
    }
    void getEstablishedDate(){
        bank::getEstablishedDate();
    }
    void getBankType(){
        bank::getBankType();
    }
    void getInfo(){
        bank::getInfo();
    }
};
//---------------------------------------------------------------------------------------------------------------------

class ICICI:public bank,public loan{public:
    void getName(){
        bank::getName();
    }
    void getEstablishedDate(){
        bank::getEstablishedDate();
    }
    void getBankType(){
        bank::getBankType();
    } 
    void getInfo(){
        bank::getInfo();
    }
};
//---------------------------------------------------------------------------------------------------------------------

class IOB:public bank,public loan{public:
    void getName(){
        bank::getName();
    }
    void getEstablishedDate(){
        bank::getEstablishedDate();
    }
    void getBankType(){
        bank::getBankType();
    } 
    void getInfo(){
        bank::getInfo();
    }
};
//-----------------------------------------------------------------------------------------------------------------------------

class compare{public:

    //compare interest Rates of different banks
    void compareInterestRate(HDFC h,SBI s,ICICI i,IOB o){
        if(h.interestRate>s.interestRate&&h.interestRate>i.interestRate&&h.interestRate>o.interestRate){
            cout<<"HDFC has the highest interest rate"<<endl;
        }
        else if(s.interestRate>h.interestRate&&s.interestRate>i.interestRate&&s.interestRate>o.interestRate){
            cout<<"SBI has the highest interest rate"<<endl;
        }
        else if(i.interestRate>h.interestRate&&i.interestRate>s.interestRate&&i.interestRate>o.interestRate){
            cout<<"ICICI has the highest interest rate"<<endl;
        }
        else if(o.interestRate>h.interestRate&&o.interestRate>s.interestRate&&o.interestRate>i.interestRate){
            cout<<"IOB has the highest interest rate"<<endl;
        }
    }
};