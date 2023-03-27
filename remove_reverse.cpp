#include <bits/stdc++.h>
using namespace std;
// Helper function which will return the final string
string removeReverse(string S)
{
    // code here
    // n is the size of the original string S
    int n = S.size();
    // count vectror which will store the count of
    // each character i.e how many times the character
    // appears in the string
    vector<int> count(26, 0);
    // Character counting process
    for (int i = 0; i < n; i++)
    {
        count[S[i] - 'a']++;
    }
    // Two pointer which is initially pointing
    // to the first and last character
    int start = 0;
    int end = n - 1;
    // dir variable will keep the track of
    // direction of traversing the string
    int dir = 0;
    // Iterate the string, S
    while (start <= end)
    {
        // If traversing process is continuing from front to back of the string
        if (dir == 0)
        {
            // If number of appearence of any character is 1
            // then we just increase the start pointer
            if (count[S[start] - 'a'] == 1)
            {
                // increament the start pointer by 1
                start++;
            }
            // If number of appearence of any character is not 1
            // then we follow some steps
            else
            {
                // We just decrease the count of current character by 1
                count[S[start] - 'a']--;
                // To delete the current character we have changed
                // the character by another character '@'
                S[start] = '@';
                // Incease the start pointer
                start++;
                // Change the direction of traversing
                dir = 1;
            }
        }
        // If traversing process is continuing from back to front of the string
        else
        {
            // If number of appearence of any character is 1
            // then we just decrease the end pointer
            if (count[S[end] - 'a'] == 1)
            {
                // Decreament the end pointer by 1
                end--;
            }
            // If number of appearence of any character is not 1
            // then we follow some steps
            else
            {
                // We just decrease the count of current character by 1
                count[S[end] - 'a']--;
                // To delete the current character we have changed
                // the character by another character '@'
                S[end] = '@';
                // decrease the end pointer
                end--;
                // Change the direction of traversing
                dir = 0;
            }
        }
    }
    // Answer string to store the final string
    string ans = "";
    // Traverse the original string
    for (int i = 0; i < n; i++)
    {
        // To get final string we have to ignore '@' character
        // as it is introduced to identify the index at which deleted
        // characters were present
        if (S[i] != '@')
        {
            // Add with answer string, ans
            ans.push_back(S[i]);
        }
    }
    // If dir value 1 i.e we move from end to front
    // that is we got the final string in reverse way
    // so we have to reverse it again
    if (dir == 1)
    {
        // Now reverse the string to obtain acctual string
        reverse(ans.begin(), ans.end());
    }
    // NOw finally return the string to main function
    return ans;
}
// Driver code
int main()
{
    // Declaration of original string
    string s;
    // Initialization of original string
    s = "abab";
    cout << removeReverse(s) << endl;

    return 0;
}