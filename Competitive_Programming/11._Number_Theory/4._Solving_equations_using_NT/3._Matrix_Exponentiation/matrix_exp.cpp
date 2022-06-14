#include <iostream>
using namespace std;

void multiply(int A[2][2], int B[2][2])
{
    // store in
    int C[2][2];
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            A[i][j] = C[i][j];
    }
}

void power(int A[2][2], int n)
{
    if (n == 1)
        return;

    power(A, n / 2);
    multiply(A, A);
    if (n % 2 == 1)
    {
        int M[2][2] = {{1, 1}, {1, 0}};
        multiply(A, M);
    }
}

int fib(int n)
{
    if (n <= 1)
        return n;
    int A[2][2] = {{1, 1}, {1, 0}};
    power(A, n - 1);
    return A[0][0];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    cout << endl;
    return 0;
}
// void multiply(int A[2][2], int B[2][2])
// {
//     // store in
//     int C[2][2];
//     C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
//     C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
//     C[1][0] = A[1][0] * B[0][0] + A[0][1] * B[1][0];
//     C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < 1; j++)
//             A[i][j] = C[i][j];
//     }
// }
