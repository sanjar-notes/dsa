#include<iostream>
using namespace std;

int powf(int x, int y)
{
    if(y==0)	// prank case
        return 1;
    int ans = powf(x, y/2);
    ans*=ans;
	if(y%2==1)
        return x*ans;
	return ans;
}

int main()
{
    int x, y;
    cin >> x >> y; // 0 ^ 0 is 1
	// Naive solution - Time = O(y) y multiplications
    // Can we be quick- O(log n) - log n multiplications, log memory
    cout << powf(x, y) << endl;
}
