#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool wordBreak(string s, vector<string> &wordDict)
{
    int size = s.size(), wordSize = wordDict.size();
    vector<bool> DP(size, false);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < wordSize; ++j)
        {
            if (!DP[i] && i + 1 == wordDict[j].size())
            {
                string sub = s.substr(0, wordDict[j].size());
                DP[i] = sub == wordDict[j];
            }
            else if (!DP[i] && i + 1 >= wordDict[j].size() && DP[i - wordDict[j].size()])
            {
                string sub = s.substr(i + 1 - wordDict[j].size(), wordDict[j].size());
                DP[i] = sub == wordDict[j];
            }
        }
    }

    return DP[size - 1];
}