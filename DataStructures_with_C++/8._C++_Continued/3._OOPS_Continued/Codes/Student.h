#include <iostream>
using namespace std;
class Student
{
private:
    string name;

public:
    Student(/* args */);
    void print()
    {
        cout << "Student\n";
    }
    ~Student();
};

Student::Student(/* args */)
{
}

Student::~Student()
{
}
