#include <iostream>
using namespace std;
class Triplet
{
public:
    int x;
    int y;
    int gcd;
};

Triplet extendedEuclid(int a, int b)
{
    //base case
    if (b == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1; // a*x
        ans.y = 0;
        return ans;
    }
    //Extended Euclidean algorithms
    Triplet smallAns = extendedEuclid(b, a % b); // keeping smaller on the right always
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}
int main()
{
    int a = 17, b = 6;
    // cin >> a >> b >> c;
    // printf("Solving %i*x + %i*y = gcd(%i, %i)\n", a, b, a, b);
    Triplet ans = extendedEuclid(a, b);
    cout << ans.x << " " << ans.y << " " << ans.gcd;
    cout << endl;
    return 0;
}
