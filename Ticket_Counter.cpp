// Add header file
#include <bits/stdc++.h>
using namespace std;

// Function to calculate last people in the queue

int lastPeople(int N, int K)
{
    // Declare an integer array of size N
    int a[N];

    // Store integer from 1 to N in that array
    for (int i = 0; i < N; i++)
    {
        // As the array is 0 based indexing array so we have taken (i+1) value
        a[i] = (i + 1);
    }
    // Declare two pointer
    int i, j;
    // Initialize i and j
    i = 0;
    j = N - 1;
    // Now move those pointer using a loop
    // I is from front side and j is from back side of the array both by K unit
    // The Loop will be running until distance between two pointer
    //  become K or less than K
    while ((j - i + 1) > K)
    {
        // Increase i pointer by K unit
        i += K;
        // Decrease j pointer by K unit
        j -= K;
    }
    // Check whether i value is less or equal to j or not
    if (i <= j)
    {
        // If yes then j pointer points to the last people
        // We can directly return the value of array at index j
        return a[j];
    }
    // If the above condition is not true the i pointer
    // will point to the last people i.e return a[i]

    return a[i];
}

// Main function
int main()
{
    int N, K;
    // Taking input in variable N and K
    cin >> N >> K;

    // Function to calculate last people
    cout <<"The last person to get the ticket will be "<<lastPeople(N, K);
    return 0;
}