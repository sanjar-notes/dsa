#include <iostream>
using namespace std;

int balancedBTs(int h);

int main()
{
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}

int balancedBTs(int h)
{
    if (h <= 1)
        return 1;
    int trees[h + 1] = {1, 1}; // for h=0 and h=1
    int k = 1E9 + 7; // doublt to i to implicit

    long a, b; // we need long buffers, int* int is int

    for (int i = 2; i < h + 1; i++)
    {
        a = trees[i - 1] % k;
        b = trees[i - 2] % k;
        trees[i] = (a * ((a + (2 * b) % k) % k)) % k; // implicit int, as k is well within 32 bits, 2.1e9
    }

    return trees[h]; // get f(h)
}
