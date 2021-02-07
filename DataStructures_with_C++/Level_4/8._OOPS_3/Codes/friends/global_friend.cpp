#include <iostream>
using namespace std;

// void f();    // No need of this

class A
{
    int a;
    friend void f();
};

class B
{
    int b;
    friend void f();
};

void f()
{
    A x;
    B y;
    cout << x.a + y.b;
}

int main()
{
    f();
    cout << endl;
    return 0;
}
