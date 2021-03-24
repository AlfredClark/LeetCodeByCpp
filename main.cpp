#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        stack<int> stk;
        int med = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < med)
                return true;
            while (!stk.empty() && stk.top() < nums[i]) {
                med = max(stk.top(), med);
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution solution;
    int num[] = {-1, 3, 2, 0};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    cout << solution.find132pattern(nums) << endl;
    return 0;
}

