#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>

int main()
{
    unordered_map<string, int> ourMap;
    pair<string, int> p("abc", 1);

    // insert
    // method 1
    // ourMap.insert(p);
    // method 2
    ourMap["abc"] = 1;
    cout << endl;

    // find or access
    // method 1
    cout << ourMap["abc"] << endl;
    // method 2, at is safer
    cout << ourMap.at("abc") << endl;

    // check presence
    // 1.
    // using [] if key is not present - has A SIDE EFFECT
    // it adds the key implicitly. Even if we just used it for printing.
    // 2. at gives exception if not present
    // 3. checking for presence: ourMap.count()!=0, this is true if present

    // check size
    cout << ourMap.count("abc");

    // erase an element
    // ourMap.at("dfd");
    return 0;
}

// All things are the same for map, except that things here are O(1)
