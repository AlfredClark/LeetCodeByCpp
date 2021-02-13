#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};

int main() {
    Solution solution;
    int num[] = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    for (int i: solution.findDisappearedNumbers(nums))
        cout << i << " ";
    return 0;
}
