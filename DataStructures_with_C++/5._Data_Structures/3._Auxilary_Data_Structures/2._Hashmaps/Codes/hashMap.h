#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    // we could have made this friend, but it is okay.
    string key;
    V value;
    MapNode *next;
    // Using closed hashing or seperate chaining
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    // If we want the whole node to be destroyed, then we make a recursive destructor
    ~MapNode()
    {
        delete next; // this will automatically call to delete the next node
        // at last delete NULL will be ignored, then all nodes will be deleted, recusrion return phase.
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets; // array of node pointers
    int count;
    int numBuckets; // required for the compression function

    int getBucketValue(string key)
    {
        int hashCode = 0;
        // find the hashCode for string.
        // let us use base prime.
        int multiplier = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += (key[i] * multiplier);
            hashCode %= numBuckets;
            multiplier *= 37;
            multiplier %= numBuckets; // to protect from overflow, does not changes
            // due to property of modulus function
        }
        return hashCode % numBuckets;
    }

    void rehash()
    {
        std::cout << "Rehash Called\n";
        int oldBucketCount = count;
        MapNode<V> **temp = buckets;

        count = 0;
        numBuckets *= 2;
        buckets = new MapNode<V> *[numBuckets] {}; // initialized as 0
        for (int i = 0; i < oldBucketCount; i++)
        {
            if (temp[i] != NULL)
            {
                MapNode<V> *head = temp[i];
                while (head != NULL)
                {
                    MapNode<V> *tbd = head;
                    insert(head->key, head->value); // count is taken care of
                    head = head->next;
                    tbd->next = NULL;
                    delete tbd; // deleting at the node level, this ensures less memory usage
                }
            }
            // the bucket becomes empty, or is empty
        }
        delete temp; // delete the old bucket

    }

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets] { 0 };
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++) // coz the keys could be anywhere
            delete buckets[i];
        delete buckets; // delete the bucket array itself
    }

    int size()
    {
        return count;
    }

    int capacity()
    {
        return numBuckets;
    }

    float getLoadFactor()
    {
        return (count + 0.0) / numBuckets;
    }

    void insert(string key, V value)
    {

        // check if the load factor will be low enough
        if ((count + 1.0) / numBuckets > 1) // 1 will be added
            rehash();

        // add the value as it is.

        // getting the bucket index
        int bucketIndex = getBucketValue(key);
        MapNode<V> *head = buckets[bucketIndex];
        // there are 3 scenarios
        // 1. The place is unoccupied, add the value as the head of the list.
        // 2. The place is occupied, check if the node is present: If yes: update the value
        // 3. If not found, we add the new value as head; 1 and 3 are the same.

        // We can do this using a single while loop
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value; // value updated done., no count increment here
                return;
            }
            head = head->next;
        }

        MapNode<V> *newnode = new MapNode<V>(key, value); // newnode create
        newnode->next = buckets[bucketIndex];             // newnode attached to the LL as its head
        buckets[bucketIndex] = newnode;                   // head value replaced as the newnode
        count++;
    }

    V getValue(string key)
    {
        // getting the bucket index
        int bucketIndex = getBucketValue(key);
        MapNode<V> *head = buckets[bucketIndex];

        // there are 3 scenarios
        // 1. The key is found: return
        // 2. Not found return 0

        while (head != NULL)
        {
            if (head->key == key)   // searching
                return head->value;
            head = head->next; // traverse ahead
        }

        // if we reach here, then the key is absent from the bucket
        return 0; // signifies values not found
    }

    V remove(string key)
    {
        // getting the bucket index
        int bucketIndex = getBucketValue(key);
        MapNode<V> *head = buckets[bucketIndex];

        // there are 3 scenarios
        // 1. The key is found: It is at head, change head.
        // 2. Key is found, at somewhere in the middle, we need the prev node
        // 3. key is not found, return some symbolic value
        MapNode<V> *prev = NULL;

        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL) // only possible
                {
                    // the first node is the keynode
                    V ret_value = head->value;
                    buckets[bucketIndex] = head->next;

                    head->next = NULL; // so that the destructor doesn't delete the whole LL
                    delete head;
                    count--;
                    return ret_value;
                }
                else
                {
                    // found key is somewhere in the middle
                    V ret_value = head->value;
                    prev->next = head->next;
                    // no changes in the head

                    head->next = NULL; // so that the destructor doesn't delete the whole LL
                    delete head;
                    count--;
                    return ret_value;
                }
            }
            prev = head;       // update the prev
            head = head->next; // update the head
        }
        // if we reach here, then the key is absent from the bucket
        return 0;
    }
};
