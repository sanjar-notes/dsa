#include <iostream>
using namespace std;

class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;
    Vehicle()
    {
        maxSpeed = 0;
        numTyres = 1;
        color = "Black";
        // cout << "Vehicle Constu Called\n";
    }

    void print()
    {
        cout << "Vehicle\n";
    }

    ~Vehicle()
    {
        // cout << "Vehicle Destu Called\n";
    }
};
