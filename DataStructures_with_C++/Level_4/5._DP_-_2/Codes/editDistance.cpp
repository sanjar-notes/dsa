// helper function
int helper(int n, int *arr)
{
    // base case: if present, return the answer
    if (arr[n] != -1)
        return arr[n];

    // else - we need to calculate it

    int n1 = n - 1, n2 = n - 1, n3 = n - 1; // max value is n-1

    n1 = helper(n - 1, arr); // steps required for n-1

    if (n % 2 == 0)
        n2 = helper(n / 2, arr); // steps required for n/2

    if (n % 3 == 0)
        n3 = helper(n / 3, arr); // steps required for n/3

    // store, we could have saved a function call if we checked if n/2 and /3 exist, that does not add to the complexity of the solution, as it is O(1)

    arr[n] = min(n1, min(n2, n3)) + 1; // (step required for the minimum dependency, among the three) + the step itself

    //return
    return arr[n];
}

// driver code, contains the store
int countStepsTo1(int n)
{
    int *arr = new int[n + 1];

    arr[0] = arr[1] = 0; //zero will never be reached, 1 is the answer we know

    for (int i = 2; i < n + 1; i++) // initialize all uncalculated values to -1
        arr[i] = -1;

    return helper(n, arr);
}
