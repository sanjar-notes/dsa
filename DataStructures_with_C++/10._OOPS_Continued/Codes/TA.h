#include "Teacher.h"
#include "Student.h"

class TA : private Teacher, public Student
{
public:
    // void print()
    // {
    //     cout << "TA";
    //     // Student::print();
    // }
};
