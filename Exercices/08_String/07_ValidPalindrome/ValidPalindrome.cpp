#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{
    string filtered;
    for (char c : s)
    {
        if (isalnum(c))
        {
            filtered += tolower(c);
        }
    }

    int left = 0, right = filtered.length() - 1;
    while (left < right)
    {
        if (filtered[left] != filtered[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}