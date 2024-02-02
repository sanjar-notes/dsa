#include <iostream>
using namespace std;

class Student
{

public:

    // Student(const Student &t)
    // {
    //     cout << "copy constructor called\n";
    // }

    void operator=(const Student &t)
    {
        cout << "copy assignment operator called\n";
    }
};

int main()
{
    // Blocks don't affect operation.
    // case 1, here copy assignment is called. Yeah Ok.
    {
        Student A;
        Student B;
        A = B;
    }

    // case 2: Here copy assignment 'should have been' called. But copy constructor is called
    // because the destination does not exist. And copy constructor is enough for the copying.
    // So no need to call the copy assignment operator.
    cout << "\n-------------------------------------------------------------\n";
    {
        Student A;
        Student B = A; //
    }
    return 0;
}
