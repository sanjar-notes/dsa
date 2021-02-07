#include "Vehicle.h"

class Car : public Vehicle
{
private:
    bool hasAC;

protected:
    float age;

public:
    Car()
    {
        hasAC = true;
        age = 0.0L;
        // cout << "Car constu called\n";
    }
    string owner;

    void print()
    {
        cout << "Car\n";
    }

    ~Car()
    {
        // cout << "Car Destu Called\n";
    }
};
