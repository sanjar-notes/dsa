---
tags:
  - STL
  - containers
---
# 1. Containers
Created Sun May 12, 2024 at 7:34 PM

## String
`strings` are a huge practically improvement over C-style strings.
They are dynamic, mutable. Each element is still a char.
```cpp
// initialization
string s; // empty string
	string s = "hello world";
	string s (s2); // deep copy
	string s (s2, startI, len); // deep copy, substring
	string s (len, fillChar); // string x(10, 'A');
	string s (s2.begin(), s2.end()); // string x(10, 'A');
	string s (vecChar.begin(), vecChar.end()); // vector initialization allowed

// getting input
cin >> s; // breaks one whitespace
getline(cin, s); // breaks on newline
	cin.ignore(); // use this between normal cin, and getline to skip annoying cursor
// print
cout << s;

// compare
s1 == s2; // equality compare
s1.compare(s2); // 0 - equal, +ve (s1 comes after s2)
	s1.compare(startI, len, s2); // compare with substring


// size
s.size(); // length
s.empty(); // is empty
s.resize();

// access
s[4] // access ith element. read/write (unsafe bound)
s.at(4); // safe bound, // throws exception
s.front(); // access first, read/write
s.back();  // access last, read/write

// append O(m+n)
string s3 = s1+s2; s1+=s2; // append
s1.append(s2); // powerful append (variates same as constructor)
	s1.append(s2, startI, len); // powerful append
	s1.append(s2, maxLen); // powerful append
	s1.append(len, fillChar); // powerful append
s.push_back(charX); // avg O(1)

// more CRUD ops // O(n)
s.substr(startI, len); // build substring

s.insert(startI, payloadStr); // insert string at element i. colliding elements pushed right
	s.insert(startI, payloadStr, startPayloadI, len);
	...
s.replace(startI, len, s2); // (startI, len, ...variations_of_constructor)
	...
s.erase(startI, len)
	s.erase(it)
	s.erase(startIt, endIt)
s.pop_back(); // O(1)
s.clear(); // delete all elements

// find substring (or single character)
s.find(s2); // first occurrence of s2, -1 if not found, // O(n)
	s.find(s2, len); // first occurence of s2 looking from `len` index onwards
	s.rfind(s2); // last occurrence of s2

// existence - // O(n)
s.starts_with();
s.ends_with();
s.find() != -1; // check existence
	s.contains(); // c++23 (CLI c++2b)

// iterator
string::iterator it = s.begin(); // index 0, rightward
string::iterator it = s.end(); // index n, rightward
it++, it--; // both possible

for(auto it = s.begin(); it != s.end(); it++)
	cout << *it;
// swap is available
```

### String functions (not methods)
```cpp
// From string
stoi(s) // string to integer
	stoi(s, startI);
	stoi(s, startI, radix=10);
	stol(); // long int

stof();
	stod(); // string to double

// To string
to_string(num)
```
Note:
-tanoc ascii to int, subtract '0', 'A'.
- int to ascii, `char()`
- When very large numbers(10<sup>18</sup>)are involved, input is taken as string, and all arithmetic ops are done by reinventing the wheel by digit extraction
- These functions work, it's `cout` that has a precision limit of 6.
## Pair
USP: easiest instance of tuple
```cpp
pair<int, int> p = {1, 3};
cout << p.first << p.second;
p.first = 23;

pair<int, int> f() { return {1, 2}; }

{1, 2} // literal notation allowed. Put OK with types. like vector<vector<int>> arr; arr.push({}); is OK
```

## Vector
USP: dynamic array, the de-facto for practical programming.
```cpp
vector<int> v;
vector<int> v (10); // size 10, filled garbage
vector<int> v (10, 0); // size 10, filled with 0s
vector<int> v1 (v2); // create and copy values

{1, 2} // literal notation allowed. ambiguous alone. Put OK with types. like vector<vector<int>> arr; arr.push({}); is OK

v[2]; // read, write access
v.front(); // access first element
v.back(); // access last element

v.size(); // current filled length of vector
v.empty(); // is empty?

v.push_back(10); // insert at back, O(1) on average
// NOTE: vector<vector<int>>.push_back(vector<int>) will cause shallow copy to be created
// https://chatgpt.com/c/67292496-6240-800d-bd99-9112d9c5faf5

v.pop_back(10); // remove last element, O(1) on average
// front operations are absent
v.insert(it, 5); // insert at given index O(n)
	// varidaic - not allowed
	v.insert(it, 2, 10); // insert 10, 10 at given index
	v.insert(it, startIt, endIt); // insert values from startIt, endIt
v.erase(iterator); // remove first instance from array, O(n)
	v.erase(startIt, endIt); // remove first instance from array, O(n)
v.clear(); // delete everything

// iterator
vector<int>::iterator it = v.begin(); // index 0, rightward
vector<int>::iterator it = v.end(); // index n, rightward

// find
find(stk.begin(), stk.end(), 30); // function not method

// looping
for(auto it = v.begin(); it != v.end(); it++) { cout << *it; }
for(auto a: v) { cout << a; }

// utils
v.sort();
v.reverse();
v.swap(v2); // symbol-data swap
v.resize(100); // make size equal to 100, discard elements if needed

// HOFs - need decltype, back_inserter
// // map - transform()
decltype(v) output (v.size());
tranform(v.begin(), v.end(), output.begin(), [](auto e){ return 1; }); // new array
	tranform(v.begin(), v.end(), v.begin(), [](){ return 1; }); // in-place

// // Filter - copy_if()
decltype(v) output;
copy_if(v.begin(), v.end(), back_inserter(output), [](){ return 1; }); // new array
	 // in-place - resize, distance
	auto it = copy_if(v.begin(), v.end(), v.begin(), [](){ return 1; });
	v.resize(distance(v.begin(), it));

// // Reduce - accumulate()
auto result = accumulate(v.begin(), v.end(), 1, [](auto accum, auto item){ return accum * item; });

// deep-clone
// Only way is to create a new vector and use constructor notation
vector<int> v2(v1.begin(), v1.end()); // even array elements are created from scratch
// by default, all ops - copy, swap, insert do shallow copy

// USELESS at, back, rbegin, rend
```

## List (linked list)
USP: ADT
```cpp
list<int> v; // doubly linked list
list<int> v (10); // size 10, filled garbage
list<int> v (10, 0); // size 10, filled with 0s
list<int> v1 (v2); // create and copy values

list<int> l { 1, 2, 3 }; // initialization list allowed
lisr<int> l (vec.begin(), vec.end()); // vector initialization allowed

// Random access not allowed
ll.front(); // last element access, write
ll.back(); // last element access, write
ll.insert(); // behavior same as vector

ll.size(); // current filled length of vector
ll.empty(); // is empty?

ll.push_back(10); // insert at back, O(1)
ll.push_front(10); // insert at front, O(1)

// iterator
vector<int>::iterator it = v.begin(); // index 0, rightward
vector<int>::iterator it = v.end(); // index n, rightward
it++, it--; // both possible

// looping
for(auto it = ll.begin(); it != ll.end(); it++) { cout << *it; }
for(auto a: ll) { cout << a; }

// other things same as vector, swap
```

## Deque (double sided vector)
USP: double sided vector.
```cpp
deque<int> v; // vector with both front, back ops
// all other things same as vector, swap
```

## Stack (strict ADT)
USP: LIFO
```cpp
stack<int> stk; // LIFO structure
// no initialization list

stk.push(); // insert O(1)
stk.pop(); // remove O(1)
stk.top(); // access - read/write O(1)

stk.size();
stk.empty();

// iterator - none

// looping
while(!stk.empty()) { cout << stk.top(); stk.pop(); }

// utils - swap
```

## Queue (strict ADT)
USP: FIFO
```cpp
queue<int> q; // LIFO structure,

// no initialization list
queue<int> q (vec.begin(), vec.end()); // vector initialization allowed

// ops same as stack
q.push();// insert O(1)
q.pop(); // remove O(1)
q.front(); // access - read/write O(1)
q.back(); // access - read/write O(1)

q.size();
q.empty();

// iterator - none

// looping
while(!q.empty()) { cout << q.front(); q.pop(); }

// utils - swap
```

## priority-queue/Heap (strict ADT)
USP: quick extrema access, quick insertion/deletion. Compared to sorted array.
```cpp
// get max, min element quickly (lgn)
priority_queue<int> pq; // max heap
priority_queue<int, vector<int>, greater<int>> pq; // min heap

// no initialization list
priority_queue<int> q (vec.begin(), vec.end()); // vector initialization allowed

// ops same as stack
pq.push();// insert - O(lgn)
pq.pop(); // remove - O(lgn)
pq.top(); // access - read/write - O(1)

pq.size();
pq.empty();

// iterator - none

// looping
while(!pq.empty()) { cout << pq.top(); pq.pop(); }

// utils - swap

// satellite data pair<int, T> works
// for min queue, repeat pair<int, T>
priority_queue<pair<int, string>> pq;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
```

## Set (balanced tree)
Remember one thing, set means - { sorted, unique }. Other 3 related structures are combinations of this.
```cpp
set<int> s; // balanced tree (detail: Red-Black-Tree)
set<int> s {1, 2, 3}; // initialization list is allowed
set<int> q (vec.begin(), vec.end()); // vector initialization allowed
set<int> s (s2.begin(), s2.end()); // deep clone
set<int, greater<int>> rs; // reversed (higher on the left)

s.insert(1);// insert - O(lgn)
s.erase(it); // remove - O(lgn)
	s.erase(5); // deletes the element (yes close polymorh)
	s.erase(startI, endI); // remove - O(lgn)

s.count(23);// exists? - 1 means true, 0 means false - O(lgn)
auto it = s.find(1); // get iterator to element - O(lgn), returns s.end() if not found
*it; // access - read ONLY (access requires finding) - O(1)
auto it = lower_bound(2);  // O(lgn)
auto it = upper_bound(23); // O(lgn)

// min, max
auto minIt = s.begin();
auto maxIt = s.rbegin();

s.size();
s.empty();

// iterator
s.begin(); // moves in sorted order
s.end();

// looping
for(auto it = s.begin(); it != s.end(); it++) { cout << *it; }
for(auto a: s) { cout << a; }

// utils - swap

// satellite data pair<int, T> works
set<pair<int, string>> s;
set<pair<int, string>, greater<pair<int, string>>> rs; // reversed
```

### Multi-set (not used frequently)
sorted. not unique.
```cpp
multiset<int> s;
multiset<int> s {1, 2, 3}; // initialization list is allowed
multiset<int> q (vec.begin(), vec.end()); // vector initialization allowed
multiset<int> s (s2.begin(), s2.end()); // deep clone
multiset<int, greater<int>> rs; // (higher on the left)

s.insert(1);// insert - O(lgn)
s.erase(it); // remove - O(lgn), only erases one occurence (relevant if multiple are present)
	s.erase(5); // deletes all such elements (yes close polymorh) - DANGEROUS
	s.erase(startI, endI); // remove - O(lgn)

s.count(23);// exists? - frequency, 0 means no existent - O(lgn)
auto it = s.find(1); // get first occurence iterator to element - O(lgn), returns s.end() if not found
*it; // access - read ONLY (access requires finding) - O(1)
auto it = lower_bound(2); // first occurrence
auto it = upper_bound(23); // last occurrence

s.size();
s.empty();

// min, max
auto minIt = s.begin();
auto maxIt = s.rbegin();

// iterator
s.begin(); // moves in sorted order
s.end();

// looping
for(auto it = s.begin(); it != s.end(); it++) { cout << *it; }
for(auto a: s) { cout << a; }

// utils - swap, lower_bound, upper_bound

// satellite data pair<int, T> works
multiset<pair<int, string>> s;
multiset<pair<int, string>, greater<pair<int, string>>> rs; // reversed
// FYI: multiset is not stable (same value)
```

### Unordered set (actual math set)
not sorted. unique.
```cpp
unordered_set<int> s;
unordered_set<int> s {1, 2, 3}; // initialization list is allowed
unordered_set<int> q (vec.begin(), vec.end()); // vector initialization allowed
unordered_set<int> s (s2.begin(), s2.end()); // deep clone

s.insert(1);// insert - O(1)
s.erase(it); // remove - O(1), only erases one occurence (relevant if multiple are present)
	s.erase(5); // deletes all such elements (yes close polymorh) - DANGEROUS
	s.erase(startI, endI); // remove - O(lgn)

s.count(23);//// exists? - 1 means true, 0 means false - O(1)
auto it = s.find(1); // get iterator to element - O(1), returns s.end() if not found
*it; // access - read ONLY (access requires finding) - O(1)
// lower_bound, upper_bound DO NOT work

s.size();
s.empty();

// iterator
s.begin(); // first element
s.end(); // last element

// looping
for(auto it = s.begin(); it != s.end(); it++) { cout << *it; }
for(auto a: s) { cout << a; }

// utils - swap
// no satellite data pair<int, T> without hash function. Fix: use un*map instead of un*set :)
```


Note:
- `multiset` - syntax same as set. sorted. not unique.
- `unordered_set` - syntax same as set. not sorted. unique.
- `unordered_multiset` - syntax same as set. non-sorted, non-unique. USP (over vector): fast access, insert, deletion
- `unordered*` containers don't support easy satellite data. You have to provide a hash function. Fix: Simply prefer using `unordered*map` versions here. Since it's `<int, T>` by default.


## Map
Keyed data structure.
{ sorted, unique }. Other 3 related structures are combinations of this.
```cpp
map<int, int> mp;
map<int, int> mp { {1: 10}, {2, 20}, {3, 30} }; // initialization list is allowed
map<int, int> mp (mp2.begin(), mp2.end()); // deep clone
map<int, T, greater<int>> rmp; // reversed (higher on the left)
// key can be any trivial combination, int x string x pair
// value can be anything

// ops same as stack, but named diff
mp.insert(1);// insert - O(lgn)
	mp[1] = 2; // insert/write in one go, returns NULL if that value does not exist.

mp.erase(it); // remove - O(lgn)
	mp.erase(5); // deletes the element (yes close polymorh)
	mp.erase(startI, endI); // remove - O(lgn)

mp.count(23);// exists? - 1 means true, 0 means false - O(lgn)
auto it = mp.find(1); // get iterator to element - O(lgn), returns mp.end() if not found
auto it = mp.lower_bound(2); // first occurrence of key
auto it = mp.upper_bound(23); // last occurrence of key
(*it).first; // read key
(*it).second, (*it).second = 4; // read/write value

mp.size();
mp.empty();

// min, max
auto minIt = mp.begin();
auto maxIt = mp.rbegin();

// iterator
mp.begin(); // moves in sorted order
mp.end();

// looping
for(auto it = s.begin(); it != s.end(); it++) { cout << *it; }
for(auto a: mp) { cout << a.first << a.second << endl; } // internally behaves like a collection of pairs

// utils - swap

// satellite data - no speciality needed. Already of the form <int, T>
```

### Multimap (not used frequently)
sorted. not unique.
```cpp
multimap<int, int> mp;
multimap<int, int> mp { {1: 10}, {2, 20}, {3, 30}, {3, 40} }; // initialization list is allowed
multimap<int, int> mp (mp2.begin(), mp2.end()); // deep clone
multimap<int, T, greater<int>> rmp; // reversed (higher on the left)

// min, max
auto minIt = mp.begin();
auto maxIt = mp.rbegin();

// everything same as map, only it can store multiple keys
// only mpp[key] cannot be used here, since ambiguous access

// satellite data - no speciality needed. Already of the form <int, T>
```

### Unordered (actual raw hashmap)
not sorted. unique.
```cpp
unordered_map<int, int> mp;
unordered_map<int, int> mp { {1: 10}, {2, 20}, {3, 30} }; // initialization list is allowed
unordered_map<int, int> mp (mp2.begin(), mp2.end()); // deep clone

// same as map
// lower_bound DOESNT work
// upper_bound DOESNT work

// satellite data - no speciality needed. Already of the form <int, T>
```


Note:
- `multimap` - syntax same as set. sorted. not unique.
- `unordered_map` - syntax same as set. not sorted. unique.
- `unordered_multimap` - syntax same as set. non-sorted, non-unique. USP: keyed, fast access, insert, deletion
- Satellite data is already covered in all map types, they support `<int, T>` by default.

## Bitset
Useful in fast solving of problems
```cpp
bitset<32> my_set; // clear constructor all 0s
bitset<32> my_set (13); // stores bit representation of the number
bitset<sizeof(int) * 8> my_set; // dynamic size without experimenation

my_set.test(i); // access bit
my_set.set(i, val=1); // set value, default 1
my_set.reset(i); // set to 0
my_set.flip(i);

my_set.to_ulong(); // set to long, convert to int if needed
my_set.to_string();

my_set.any(); // true if no bit is 0
my_set.all(); // true if all bits 1
my_set.none(); // true if all bits 0
my_set.count(); // number of set bits
```