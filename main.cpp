#include <bits/stdc++.h>

using namespace std;

class NumArray {
public:
    int *sums;

    NumArray(vector<int> &nums) {
        int n = nums.size();
        sums = new int[n + 1];
        for (int i = 0; i < n; ++i)
            sums[i + 1] = sums[i] + nums[i];
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

int main() {
    int num[] = {-2, 0, 3, -5, 2, -1};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    NumArray *obj = new NumArray(nums);
    int param_1 = obj->sumRange(2, 5);
    cout << param_1 << endl;
    return 0;
}