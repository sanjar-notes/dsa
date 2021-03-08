#include <iostream>
using namespace std;
class Teacher
{
private:
    string name;

public:
    Teacher(/* args */);
    void print()
    {
        cout << "Teacher\n";
    }
    ~Teacher();
};

Teacher::Teacher(/* args */)
{
}

Teacher::~Teacher()
{
}
