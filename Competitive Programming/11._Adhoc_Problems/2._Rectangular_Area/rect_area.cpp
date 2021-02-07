#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> points[n + 1];   // need a point on the y axis the left most one

    // get the coordinates, and better than dividing the input by 4, and multiplying 4 at the end, we let the input as if it were only in the first quadrant
    // Advantage = no problems with floats etc.
    int hmax = -1;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> points[i].first >> points[i].second;
        if (hmax < points[i].second)
            hmax = points[i].second;
    }
    points[0].first = 0, points[0].second = hmax;
    sort(points + 1, points + n + 1);

    int neff = 0, hmaxl;
    for (int i = 1; i < n + 1; i++)
    {
        hmaxl = points[i].second;
        while (i < n && points[i].first == points[i + 1].first)
        {
            if (hmaxl < points[i + 1].second)
                hmaxl = points[i + 1].second;
            i++;
        }
        points[i].second = hmaxl;
        neff++;
    }

    int area = 0;
    for (int i = neff; i > 0; i--) // Every points has height on the left same as its height till the point on the left
        area += (points[i].first - points[i - 1].first) * points[i].second;

    cout << area; // no need of *4
    return 0;
}

