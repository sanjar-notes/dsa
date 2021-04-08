#include "template_stackUsingDynamicArray.cpp"
int main()
{
    Stack<char> p;
    p.push(65);
    p.push(65 + 1);
    p.push(65 + 2);
    p.print();

    return 0;
}
