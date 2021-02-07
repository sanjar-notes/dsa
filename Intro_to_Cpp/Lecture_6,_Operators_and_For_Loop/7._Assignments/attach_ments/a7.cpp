/*
                                    <---Check Number sequence--->

You are given S a sequence of n integers i.e. S = s1, s2, ..., sn. Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in such a way that the first part is strictly decreasing while the second is strictly increasing one.
That is, in the sequence if numbers are decreasing, they can start increase at one point. And once number starts increasing, they cannot decrease at any point further.
Sequence made up of only increasing numbers or only decreasing numbers is a valid sequence. So in both the cases, print true.
You just need to print true/false. No need to split the sequence.
Input format :
Line 1 : Integer n
Line 2 : n integers (separated by space)
Output Format :
"true" or "false" (without quotes)
Sample Input 1 :
5
9 8 4 5 6
Sample Output 1 :
true
Sample Input 2 :
3
1 2 3
Sample Output 2 :
true
Sample Input 3 :
3
8 7 6
Sample Output 3 :
true
Sample Input 4 :
6
8 7 6 5 8 2
Sample Output 4 :
false
*/

#include <iostream>
using namespace std;

int main()
{
    // Write your code here
    // The difference or pairwise delta across the sequence should change the sign "at most" once(strictly monotonic).
    // As the sequence is strictly monotonic, the delta can only change can be from -ve to +ve.
    // Due to the atmost condition, a wholly increasing or decreasing sequence is a valid sequence.
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "true\n";
        return 0;
    }
    int count = 0;
    int first, mid, last; // taking them as they are true by default anyways
    cin >> first;
    cin >> mid;
    cin >> last;
    int d1 = mid - first;
    int d2 = last - mid;
    for (int i = 0; i < n - 3; i++)
    {
        d1 = d2;
        mid = last;
        cin >> last;
        d2 = last - mid;
        if (d1 * d2 < 0)
        {
            if (count >= 1)
            {
                cout << "false\n";
                return 0;
            }
                count+=1;
        }
    }
    cout << "true\n";
}
