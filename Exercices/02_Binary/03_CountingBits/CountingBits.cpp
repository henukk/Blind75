#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> ret = vector<int>(n + 1, 0);
    int i, act, tmp;
    for (i = 1; i <= n; ++i)
    {
        act = 0;
        tmp = i;
        while (tmp > 0)
        {
            act += tmp % 2;
            tmp /= 2;
        }
        ret[i] = act;
    }
    return ret;
}