#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};

int main() {
    Solution solution;
    int num[] = {1, 3, 5, 8, 23, 63, 11, 9, 3, 2, 66, 23};
    vector<int> row(num, num + sizeof(num) / sizeof(int));
    cout << solution.arrayPairSum(row);
    return 0;
}
