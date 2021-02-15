#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int max_count = 0, count = 0;
        for (int num: nums)
            if (num)
                count++;
            else {
                max_count = max(max_count, count);
                count = 0;
            }
        max_count = max(max_count, count);
        return max_count;
    }
};

int main() {
    Solution solution;
    int num[] = {1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1};
    vector<int> row(num, num + sizeof(num) / sizeof(int));
    cout << solution.findMaxConsecutiveOnes(row);
    return 0;
}
