#include <vector>
#include <climits>

template <typename T>
class PriorityQueue
{
    vector<T> pq;

private:
    // internal software

    /*
    bool heapPropertyCheck(int par)
    { // only for non-duplicates too elements
        if (2 * par + 1 >= pq.size())
            return true;
        else // the left one exists
        {
            if (pq.at(2 * par + 1) >= pq.at(par)) // left one satisies the property
            {
                // checking the right one
                if (2 * par + 2 < pq.size()) // it exists
                {
                    if (pq.at(2 * par + 2) >= pq.at(par))
                        return data;
                    return false; // right child less than parent
                }
                return data; // right does not exist
            }
            // child less than the parent
            return false;
        }
    }
    */

public:
    PriorityQueue()
    {
        pq.resize();
    }

    bool isEmpty()
    {
        return pq.empty(); // returns true if empty
    }

    int getMin()
    {
        if (!pq.empty())
            return pq.at(0);
        return -1001;
    }

    int getSize()
    {
        return pq.size();
    }

    void insert(T data)
    {
        // insert at the end
        pq.push_back(data);
        // check if property is satisfied, else sift up
        // parInent < childIn
        int childIn = pq.size() - 1;
        int parIn = (childIn - 1) / 2;
        int temp;
        while (childIn > 0 && pq.at(parIn) > pq.at(childIn)) // no need to heck anything else
        {
            temp = pq.at(parIn);
            pq.at(parIn) = pq.at(childIn);
            pq.at(childIn) = temp;

            childIn = parIn;
            parIn = (childIn - 1) / 2;
        }
    }

    void removeMin()
    {
        if (pq.empty())
        {
            cout << "Priority Queue is empty\n";
            return;
        }

        if (pq.size() == 1)
        {
            pq.pop_back();
            return;
        }

        // copy to root, pop back
        pq.at(0) = pq.at(pq.size() - 1);
        pq.pop_back();
        int par = 0;

        // we have checked that the CBT is not a single node, we stop at the end, i.e when no left child exists
        while (2 * par + 1 < pq.size())
        {
            // the left one exists for sure, can't say about the right
            if (2 * par + 2 < pq.size()) // right exists
            {
                int tb_swap = pq.at(2 * par + 1) <= pq.at(2 * par + 2) ? 2 * par + 1 : 2 * par + 2;
                int temp = pq.at(par);
                pq.at(par) = pq.at(tb_swap);
                pq.at(tb_swap) = temp;
                par = tb_swap;
            }
            else
            {
                if (input[2 * par + 1] < input[par])
                {
                    int temp = pq.at(par);
                    pq.at(par) = pq.at(2 * par + 1);
                    pq.at(2 * par + 1) = temp;
                }
                break;
            }
        }
    }

    void print()
    {
        for (auto x : pq)
            cout << x << " ";
        cout << "\b\b  \n";
    }
};
