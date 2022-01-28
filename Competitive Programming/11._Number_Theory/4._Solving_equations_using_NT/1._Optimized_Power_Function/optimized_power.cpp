#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        int ans = power(x, n / 2);
        return ans * ans;
    }
    else
    {
        int ans = power(x, n / 2);
        return ans * ans * x;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
    cout << endl;
    return 0;
}
