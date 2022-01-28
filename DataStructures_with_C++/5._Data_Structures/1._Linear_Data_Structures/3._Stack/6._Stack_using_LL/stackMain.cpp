#include "stackUsingLL.cpp"
int main()
{
    Stack<int> p;
    p.push(65);
    p.push(65 + 1);
    p.print();
    cout << p.getSize();
    return 0;
}
