#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        deque<int> maxQue, minQue;
        int left = 0, right = 0, res = 0;
        while (right < nums.size()) {
            while (!maxQue.empty() && nums[right] > maxQue.back())
                maxQue.pop_back();
            while (!minQue.empty() && nums[right] < minQue.back())
                minQue.pop_back();
            maxQue.push_back(nums[right]);
            minQue.push_back(nums[right]);
            while (!maxQue.empty() && !minQue.empty() && maxQue.front() - minQue.front() > limit) {
                if (maxQue.front() == nums[left])
                    maxQue.pop_front();
                if (minQue.front() == nums[left])
                    minQue.pop_front();
                left++;
            }
            res = max(res, right - left + 1);
            right++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int num[] = {4, 2, 2, 2, 4, 4, 2, 2};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    cout << solution.longestSubarray(nums, 0);
    return 0;
}