#include <iostream>
using namespace std;

int mod_exp(int a, int b, int c)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;

    long smallAns = mod_exp(a, b / 2, c);
    smallAns = (smallAns * smallAns) % c;

    if (b % 2 == 1)
        smallAns = (smallAns * a) % c;
    return int(smallAns);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << mod_exp(a, b, 1000000000 + 7);
    return 0;
}
