#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *arr;      // head of the dynamic array
    int capacity;  // maximum capacity without resizing
    int nextIndex; // write head, does not hold a value

public:
    DynamicArray(int capacity = 5)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        nextIndex = 0;
    }

    DynamicArray(const DynamicArray &t)
    {
        cout << "copy constructor called\n";
        arr = new int[t.capacity];
        capacity = t.capacity;
        nextIndex = t.nextIndex;

        // copy the values
        for (int i = 0; i < nextIndex; i++)
            arr[i] = t.arr[i];
    }

    void operator=(const DynamicArray &t)
    {
        cout << "copy assignment operator called\n";
        // array exists
        capacity = t.capacity;
        nextIndex = t.nextIndex;
        arr = new int[capacity];
        for (int i = 0; i < nextIndex; i++)
            arr[i] = t.arr[i];
    }
    void add(int data) // data is the element
    {
        // check if we are ready to write
        if (nextIndex == capacity)
        {
            // create a new array of double
            int *new_arr = new int[capacity * 2];

            // copy the values
            for (int i = 0; i < capacity; i++)
                new_arr[i] = arr[i];

            //delete old array
            delete[] arr;

            // store head of the new array
            // and change the value of capacity
            capacity *= 2;
            arr = new_arr;
        }

        // ready to write
        arr[nextIndex] = data;
        nextIndex++;
        // Don't write crappy code
    }

    void add(int data, int index) // data is the element
    {
        // check if we are ready to write
        if (index > nextIndex)
            return; //not allowed

        if (index == nextIndex)
            add(data);
        else
            arr[index] = data;
    }

    int get(int index) // return value at index, -1 if index nonexistent
    {
        if (index < nextIndex)
            return -1;
        return arr[index];
    }

    // prints the whole array
    void print_info()
    {
        cout << "Size: " << nextIndex << ", Capacity: " << capacity << "\n[";
        for (int i = 0; i < nextIndex; i++)
            cout << arr[i] << ", ";
        if (nextIndex == 0)
            cout << "Empty]\n";
        else
            cout << "\b\b]\n";
    }
    // ~DynamicArray()
    // {
    //     delete[] arr;
    //     capacity = 0;
    //     // the stack data members will go out of scope automatically
    // }
};

int main()
{
    {
        DynamicArray A;
        DynamicArray B;
        A = B;
    }

    cout << "\n-------------------------------------------------------------\n";
    {
        DynamicArray A;
        DynamicArray B = A;
    }
    return 0;
}
