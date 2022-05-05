#include<iostream>
#include<string>
using namespace std;

//Base classes bank,loan
class bank{public:
    string bankName,establishedDate,bankType;
    void getName(){
        cout<<"Enter the name of the bank: ";
        cin>>bankName;
    }
    void getEstablishedDate(){
        cout<<"Enter the established date of the bank: ";
        cin>>establishedDate; cout<<endl;
    }
    void getBankType(){
        cout<<"Enter the type of the bank: ";
        cin>>bankType; cout<<endl;
    }
    void getInfo(){
        cout<<"Bank Name: "<<bankName<<endl;
        cout<<"Established Date: "<<establishedDate<<endl;
        cout<<"Bank Type: "<<bankType<<endl;
    }
};

class loan{public:
    string loanType,loanTenure;
    float interestRate;
    void getLoanType(){
        cout<<"Enter the types of the loan available: ";
        getline(cin, loanType);
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
//---------------------------------------------------------------------------------------------------------------------
//hi

