#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(bool choosePre, int cur, vector<int> &nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        dfs(false, cur + 1, nums);
        if (!choosePre && cur > 0 && nums[cur - 1] == nums[cur]) {
            return;
        }
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        dfs(false, 0, nums);
        return ans;
    }
};

int main() {
    Solution solution;
    int num[] = {1, 2, 5, 3, 4, 2, 5};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    for (const auto &res:solution.subsetsWithDup(nums)) {
        for (auto re:res)
            cout << re << " ";
        cout << endl;
    }
    return 0;
}

