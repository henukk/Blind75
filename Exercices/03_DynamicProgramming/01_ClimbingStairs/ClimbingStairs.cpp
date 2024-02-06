#include <iostream>
#include <vector>

using namespace std;

vector<int> table = vector<int>(46, -1);
int climbStairs(int n)
{
    if (n <= 2)
        return table[n] = n;
    if (table[n] != -1)
        return table[n];

    return table[n] = climbStairs(n - 1) + climbStairs(n - 2);
}