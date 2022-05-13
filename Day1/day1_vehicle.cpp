#include <iostream>
#include <string>
using namespace std;
enum vehicleType
{
    petrol,
    diesel,
    electric,
    hybrid
};
const char *vehicleTypeString[] = {"petrol", "diesel", "electric", "hybrid"};

enum carType
{
    sedan,
    suv,
    hatchback
};
const char *carTypeString[] = {"sedan", "suv", "hatchback"};

enum bikeType
{
    scooter,
    gear_bike
};
const char *bicycleTypeString[] = {"scooter", "gear_bike"};

// Base class vehicle
class Vehicle
{
public:
    vehicleType type;
    string brand, model, color;
    int no_of_wheels;
    float mileage, price;
    // Base class constructor
    Vehicle(vehicleType type, string brand, string model, string color, float mileage, float price)
    {
        this->type = type;
        this->brand = brand;
        this->model = model;
        this->color = color;
        this->mileage = mileage;
        this->price = price;
    }
    // operator overloading
    friend bool operator<(const Vehicle &v1, const Vehicle &v2);
    //  bool operator< (const vehicle& v1){    // overloading operator < without friend
    //     return this->price < v1.price;
    // }
    friend ostream &operator<<(ostream &print, const Vehicle &v);
    virtual int getNoOfWheels() = 0;
};

bool operator<(const Vehicle &v1, const Vehicle &v2)
{ // friend function to comapre prices
    return v1.price < v2.price;
}

// Derived class-1 Car
class Car : public Vehicle
{
public:
    int no_of_persons;
    carType car_type;
    // Derived class-1 constructor
    Car(vehicleType type, string brand, string model, string color, float mileage, float price, int no_of_persons, carType car_type) : Vehicle(type, brand, model, color, mileage, price)
    {
        this->no_of_persons = no_of_persons;
        this->car_type = car_type;
    }
    int getNoOfWheels()
    {
        return 4;
    }
    friend ostream &operator<<(ostream &print, Car &v);
};

ostream &operator<<(ostream &print, Car &v)
{ // friend function to print bike details
    print << "Vehicle type: " << vehicleTypeString[v.type] << endl;
    print << "Brand: " << v.brand << endl;
    print << "Model: " << v.model << endl;
    print << "Color: " << v.color << endl;
    print << "Mileage: " << v.mileage << endl;
    print << "Price: " << v.price << endl;
    print << "No of persons: " << v.no_of_persons << endl;
    print << "Number of wheels in car 1: " << v.getNoOfWheels() << endl;
    print << "Car type: " << carTypeString[v.car_type] << endl;
    return print;
}
//---------------------------------------------------------------------------------------------------------------------------------
// Derived class-2 Bike
class Bike : public Vehicle
{
public:
    float weight;
    // vehicleType type;
    bikeType bike_type;
    // Derived class-2 constructor
    Bike(vehicleType type, string brand, string model, string color, float mileage, float price, float weight, bikeType bike_type) : Vehicle(type, brand, model, color, mileage, price)
    {
        this->weight = weight;
        this->bike_type = bike_type;
    }
    int getNoOfWheels()
    {
        return 2;
        // cout << "Enter no of wheels in your bike: " << endl;
        // cin >> no_of_wheels;
        // cout << "No of wheels in your bike: " << no_of_wheels << endl;
    }
    friend ostream &operator<<(ostream &print, Bike &v);
};

ostream &operator<<(ostream &print, Bike &v)
{ // friend function to print bike details
    print << "Vehicle type: " << vehicleTypeString[v.type] << endl;
    print << "Brand: " << v.brand << endl;
    print << "Model: " << v.model << endl;
    print << "Color: " << v.color << endl;
    print << "Mileage: " << v.mileage << endl;
    print << "Price: " << v.price << endl;
    print << "Weight: " << v.weight << endl;
    print << "Number of wheels in bike: " << v.getNoOfWheels() << endl;
    print << "Bike type: " << bicycleTypeString[v.bike_type] << endl;
    return print;
}
//---------------------------------------------------------------------------------------------------------------------------------
int main()
{
    Car c1(hybrid, "honda", "civic", "red", 25, 12000.8f, 4, sedan);
    Car c2(diesel, "honda", "city", "black", 23.4, 15000.5f, 4, suv);
    bool c = c1 < c2;

    // cout << "Is c1<c2?: " << c << endl;
    Bike b(petrol, "hero honda", "splender", "blue", 50.2, 12000.4f, 100, scooter);
    cout << endl
         << "------------------------------------------" << endl;
    //-----------------------------------------------------------------------------------------
    cout << "For car 1:\n"
         << endl;
    cout << c1 << endl;
    cout << endl
         << "------------------------------------------" << endl;
    //-----------------------------------------------------------------------------------------
    cout << "For car 2:\n"
         << endl;
    cout << c2 << endl;
    cout << endl
         << "------------------------------------------" << endl;
    //-----------------------------------------------------------------------------------------
    cout << "For bike:\n"
         << endl;
    cout << b << endl;
    cout << endl
         << "------------------------------------------" << endl;
    //-----------------------------------------------------------------------------------------
    if (c)
    {
        cout << "Car 1 is cheaper than car 2" << endl;
    }
    else
    {
        cout << "Car 2 is cheaper than car 1" << endl;
    }
    cout << endl
         << "------------------------------------------" << endl;
    return 0;
}