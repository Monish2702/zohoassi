#include <iostream>
#include <string>
using namespace std;
enum vehicle_type
{
    petrol,
    diesel,
    electric,
    hybrid
};

// Base class vehicle
class vehicle
{
public:
    vehicle_type type;
    string brand, model, color;
    int no_of_wheels;
    float mileage, price;
    // Base class constructor
    vehicle(vehicle_type type, string brand, string model, string color, float mileage, float price)
    {
        this->type = type;
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->mileage = mileage;
        this->price = price;
    }
    // operator overloading
    friend bool operator<(const vehicle &v1, const vehicle &v2);
    //  bool operator< (const vehicle& v1){    // overloading operator < without friend
    //     return this->price < v1.price;
    // }
    friend ostream &operator<<(ostream &print, const vehicle &v);
    virtual void get_no_wheels() = 0;
};
bool operator<(const vehicle &v1, const vehicle &v2)
{ // friend funcction to comapre prices
    return v1.price < v2.price;
}
ostream &operator<<(ostream &print, const vehicle &v)
{ // friend function to print vehicle details
    print << "Vehicle type: " << v.type << endl;
    print << "Brand: " << v.brand << endl;
    print << "Model: " << v.model << endl;
    print << "Color: " << v.color << endl;
    print << "Mileage: " << v.mileage << endl;
    print << "Price: " << v.price << endl;
    return print;
}
//---------------------------------------------------------------------------------------------------------------------------------
// Derived class-1 Car
class car : public vehicle
{
public:
    int no_of_persons;
    string car_type;
    // Derived class-1 constructor
    car(vehicle_type type, string brand, string model, string color, float mileage, float price, int no_of_persons, string car_type) : vehicle(type, brand, model, color, mileage, price)
    {
        this->no_of_persons = no_of_persons;
        this->car_type = car_type;
    }
    void get_no_wheels()
    {
        cout << "Enter no of wheels in your car: " << endl;
        cin >> no_of_wheels;
        cout << "No of wheels in your car: " << no_of_wheels << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------
// Derived class-2 Bike
class bike : public vehicle
{
public:
    float weight;
    string bike_type;
    // Derived class-2 constructor
    bike(vehicle_type type, string brand, string model, string color, float mileage, float price, float weight, string bike_type) : vehicle(type, brand, model, color, mileage, price)
    {
        this->weight = weight;
        this->bike_type = bike_type;
    }
    void get_no_wheels()
    {
        cout << "Enter no of wheels in your bike: " << endl;
        cin >> no_of_wheels;
        cout << "No of wheels in your bike: " << no_of_wheels << endl;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------
int main()
{
    cout << "\nVehicle_type: 0-petrol 1-diesel 2-electric 3-hybrid\n";
    car c1(hybrid, "honda", "civic", "red", 25, 12000.8f, 4, "sedan");
    cout << "For car 1: ";
    c1.get_no_wheels();
    car c2(diesel, "honda", "city", "black", 23.4, 15000.5f, 4, "sedan");
    cout << "For car 2: ";
    c2.get_no_wheels();
    int c = c1 < c2;
    cout << "Is c1<c2?: " << c << endl;
    bike b(petrol, "hero honda", "splender", "blue", 50.2, 12000.4f, 100, "mountain");
    cout << "For bike: ";
    b.get_no_wheels();
    cout << endl
         << "------------------------------------------" << endl;
    cout << c1 << endl;
    cout << endl
         << "------------------------------------------" << endl;
    cout << c2 << endl;
    cout << endl
         << "------------------------------------------" << endl;
    cout << b << endl;
    return 0;
}