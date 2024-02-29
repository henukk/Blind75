#include <iostream>
#include <pair>
#include <priority_queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    priority_queue<pair<int, int>> pq;
    vector<int> result(k);
    int i;

    for (int &num : nums) {
        ++freq[num];
    }

    for (auto &[num, freq] : freq) {
        pq.push({freq, num});
    }

    for (i = 0; i < k; ++i) {
        result[i] = pq.top().second;
        pq.pop();
    }

    return result;
}