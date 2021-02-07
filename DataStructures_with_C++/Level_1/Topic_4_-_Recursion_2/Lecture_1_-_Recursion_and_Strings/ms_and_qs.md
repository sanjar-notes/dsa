# Merge Sort Code

    Sort an array A using Merge Sort.
    Change in the input array itself. So no need to return or print anything.

    Input format :
    Line 1 : Integer n i.e. Array size
    Line 2 : Array elements (separated by space)
    Output format :
    Array elements in increasing order (separated by space)

    Constraints :
    1 <= n <= 1000

**Sample Input**

    6
    2 6 8 5 4 3

**Sample Output**

    2 3 4 5 6 8

<details> <summary><strong>Code</strong></summary>

    int *merge(int *a1, int *a2, int n1, int n2)
    {
        int *merged_array = new int[n1 + n2];
        int k = 0;
        int i = 0, j = 0;

        while (i < n1 && j < n2)
        {
            merged_array[k] = a1[i] < a2[j] ? a1[i++] : a2[j++];
            k++;
        }

        if (i==n1)
        {
            a1 = a2;
            i = j;
        }

        while (k < n1+n2)
            merged_array[k++] = a1[i++];
        return merged_array;
    }

    void mergeSort(int input[], int size)
    {
        if(size<=1)
            return;

        mergeSort(input, size/2);
        mergeSort(input + size/2, size-(size/2));

        int* ret = merge(input, input+size/2, size/2, size-(size/2));

        for(int i=0; i<size; i++)
            input[i] = ret[i];

    }

</details>

---

# Quick Sort Code

    Sort an array A using Quick Sort.
    Change in the input array itself. So no need to return or print anything.

    Input format :
    Line 1 : Integer n i.e. Array size
    Line 2 : Array elements (separated by space)
    Output format :
    Array elements in increasing order (separated by space)

    Constraints :
    1 <= n <= 1000

**Sample Input**

    6
    2 6 8 5 4 3

**Sample Output**

    2 3 4 5 6 8

<details> <summary><strong>Code</strong></summary>

    int partition(int* A, int size);


    void quickSort(int input[], int size)
    {
        if(size<=1)
            return;
        // int *pivot = partition(input, size);
        int pivot = partition(input, size);
        quickSort(input, pivot); // size = n_smaller
        quickSort(input+pivot+1, size-1-pivot); // all except smaller and pivot
    }


    int partition(int* A, int size)
    {
        int* pivot  = A;

        // count the number of elements smaller than pivot
        int i = 0, n_smaller = 0;
        while(i<size)
        {
            if(A[i] < pivot[0])
                n_smaller++; // strictly smaller
            i++;
        }

        // swap the value at the pivot element with the appropriate position of the pivot
        int pivot_value = *pivot ;
        *pivot = A[n_smaller];
        A[n_smaller] = pivot_value;
        pivot = A+n_smaller;
        //OK!!

        // we will deal only with pivot value now
        i = 0; int j = size-1;
        while(i<n_smaller && j>n_smaller)
        {
            if(A[i]<pivot_value) // ignoring if they conform
                i++;
            if(A[j]>=pivot_value) // pivot values allowed here, ignoring if they conform
                j--;
            if(A[i]>=pivot_value && A[j]<pivot_value) // swapping condition
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++; j--;
            }
        }
        return n_smaller;
    }

</details>

---
