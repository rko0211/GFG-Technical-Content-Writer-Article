// Add header file
#include <bits/stdc++.h>
using namespace std;

// Function to calculate last people in the queue

int lastPeople(int N, int K)
{
    // Declare two pointer
    int i, j;
    // Initialize i and j
    i = 1;
    j = N;
    // Declare one boolean variable to keep track which pointer should be moved
    // Initialize it by true value;
    bool dir = true;
    // Now move those pointer using a loop
    // i is from front side and j is from back side of the array moved both by K unit
    // The Loop will be running as long as i < j
    while (i < j)
    {
        // check condition if i and j pointing to the same value then control will go out of the loop
        // If the distance between i and j is less than or equal to K then also it will go out of the loop

        if ((i == j) || (j - i + 1) <= K)
        {
            break;
        }
        // Now check the value of dir variable
        // If dir==true then increase the i pointer by K unit
        if (dir == true)
        {
            i += K;
            // Reverse the value of dir variable for next iteration
            dir = false;
        }
        // If dir==false then decrease the j pointer by k unit
        else
        {
            j -= K;
            // Reverse the value of dir variable for next iteration
            dir = true;
        }
    }
    //  When control comes out of side the loop
    //  we have to check whether i and j pointing to the same value or not
     if(i == j)
     {
    //  return any of the value i or j
        return i;
     }

    //  If dir value is true in outside the loop then return the value of j
    if(dir)
    {
        return j;
    }
    // If dir value is false in outside the loop then return the value of i
    else
    {
        return i;
    }
}
// Main function
int main()
{
    int N, K;
    // Taking input in variable N and K
    N = 5;
    K = 1;

    // Function to calculate last people
    cout << "The last person to get the ticket will be " << lastPeople(N, K);
    return 0;
}