#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int maxLen = INT_MIN, minLen = INT_MAX;
        pair<int, pair<int, int>> record;
        pair<int, int> se;
        unordered_map<int, pair<int, pair<int, int> > > records;
        for (int i = 0; i < nums.size(); ++i) {
            if (!records.count(nums[i])) {
                record.first = 1;
                se.first = i;
                se.second = i;
                record.second = se;
                records[nums[i]] = record;
            } else {
                records[nums[i]].first += 1;
                records[nums[i]].second.second = i;
            }
        }
        for (auto &item : records)
            if (item.second.first > maxLen) {
                maxLen = item.second.first;
                minLen = item.second.second.second - item.second.second.first + 1;
            } else if (item.second.first == maxLen)
                minLen = min(minLen, item.second.second.second - item.second.second.first + 1);
        return minLen;
    }
};

int main() {
    Solution solution;
    int num[] = {1, 2, 2, 3, 1, 4, 2};
    vector<int> row(num, num + sizeof(num) / sizeof(int));
    cout << solution.findShortestSubArray(row);
    return 0;
}