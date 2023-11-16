#include <bits/stdc++.h>
using namespace std;
// Function to calculate minimum number buckets required for watering the plants daily
long long minimumBuckets(int N, int arr[])
{
    // code here
    // This variable is used to store the gcd value of every element of the array
    int gcdval = 0;
    for (int i = 0; i < N; i++)
    {
        // using Euclidian algorithm we can calculate GCD
        gcdval = __gcd(gcdval, arr[i]);
    }
    // Declared ans variable to store the answer of the problem
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        // For each element of the array we divide the element by their gcd value,gcdval
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
    // arr[i] represent the amount of water required for i'th plants per day
    int arr[] = {2, 6, 4, 10};

    cout << "Minimum number of buckets required: " << minimumBuckets(N, arr) << endl;
    return 0;
}