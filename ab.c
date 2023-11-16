#include <stdio.h>
#include <stdlib.h>
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
// Function to calculate the minimum number of buckets required for watering the plants daily
long long minimumBuckets(int N, int arr[])
{
    // This variable is used to store the GCD value of every element of the array
    int gcdval = 0;

    for (int i = 0; i < N; i++)
    {
        // Using Euclidean algorithm to calculate GCD
        gcdval = gcd(gcdval, arr[i]);
    }

    // Declared ans variable to store the answer of the problem
    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        // For each element of the array, we divide the element by their GCD value, gcdval
        ans += (arr[i] / gcdval) + (arr[i] % gcdval);
    }

    // Finally return the answer
    return ans;
}

// Driver function
int main()
{
    // Number of Plants
    int N = 4;

    // arr[i] represents the amount of water required for i'th plants per day
    int arr[] = {2, 6, 4, 10};

    long long result = minimumBuckets(N, arr);
    printf("Minimum number of buckets required: %lld\n", result);

    return 0;
}