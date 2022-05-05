//Passenger details
#include<iostream>
#include<string>
using namespace std;
//04/05
//A class named as passenger
class Passenger {private:
    static int count;
    int id,age;
    string name,flight;
    char class_type;

    protected: float price;
    
    public:
    Passenger(int ID,int AGE,string NAME,string FLIGHT,char CLASS_TYPE) {  //Constructor
        count++;
        id=ID;
        age=AGE;
        name=NAME;
        flight=FLIGHT;
        class_type=CLASS_TYPE;
    }
    friend void display(Passenger p);
};

int Passenger::count=0; //to realize the use of static variable

//friend function
void display(Passenger p) { //displaying the details of the passenger
        cout<<"Passenger count: "<<p.count<<endl;
        cout<<"ID: "<<p.id<<endl; 
        cout<<"Age: "<<p.age<<endl;
        cout<<"Name: "<<p.name<<endl;
        cout<<"Flight: "<<p.flight<<endl;
        cout<<"Class: "<<p.class_type<<endl;
        cout<<"Price: "<<p.price<<endl;
        cout<<"------------------------------------------------------"<<endl;
}

//Inherited class to calculate the price of the ticket
class ticket : protected Passenger{
    public:
    // ticket(int ID,int AGE,string NAME,string FLIGHT,char CLASS_TYPE) : Passenger(ID,AGE,NAME,FLIGHT,CLASS_TYPE) {}
    float price;
};

int main() {
    Passenger p1(121,18,"Monish","Spicejet",'b'); //creating an object of the class
    display(p1); //displaying the details of the object p1
    Passenger p2(498,40,"Whitman","Emirates",'e');
    display(p2);
    return 0;
}