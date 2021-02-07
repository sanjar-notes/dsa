#include "Car.h"

class Audi : public Car
{
private:
    bool hasAC;

protected:
    float age;

public:
    Audi()
    {
        hasAC = true;
        age = 0.0L;
        // cout << "Audi constu called\n";
    }
    string owner;

    void print()
    {
        cout << "Audi\n";
    }

    ~Audi()
    {
        // cout << "Audi Destu Called\n";
    }
};
