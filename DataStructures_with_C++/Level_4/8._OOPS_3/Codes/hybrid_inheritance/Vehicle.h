#include <iostream>
using namespace std;

class Vehicle
{
public:
    Vehicle()
    {
        cout << "Vehicle con\n";
    }
    ~Vehicle()
    {
        cout << "Vehicle des\n";
    }
};

class Truck : public Vehicle
{
public:
    Truck()
    {
        cout << "Truck con\n";
    }

    ~Truck()
    {
        cout << "Truck des\n";
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        cout << "Car con\n";
    }

    ~Car()
    {
        cout << "Car des\n";
    }
};

class Bus : public Car, public Truck
{
public:
    Bus()
    {
        cout << "Bus con\n";
    }
    ~Bus()
    {
        cout << "Bus des\n";
    }
};
