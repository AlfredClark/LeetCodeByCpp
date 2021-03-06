#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int maxIncreaseSubsequenceLength(vector<int> &nums) {
//        int n = nums.size();
//        if (n == 0)
//            return 0;
//        // 最大的长度记录
//        int len = 1;
//        // 直接预留了一，所以是n+1 填充时候也从1开始, 好处就是最后len长度就是结果，无需额外处理
//        int *d = new int[n + 1];
//        d[len] = nums[0];
//        for (int i = 1; i < n; ++i) {
//            if (nums[i] > d[len]) {
//                d[++len] = nums[i];
//            } else {
//                int l = 1;
//                int r = len;
//                int pos = 0;
//                while (l <= r) {
//                    int mid = (l + r) >> 1;
//                    if (d[mid] < nums[i]) {
//                        pos = mid;
//                        l = mid + 1;
//                    } else {
//                        r = mid - 1;
//                    }
//                }
//                d[pos + 1] = nums[i];
//            }
//        }
//        return len;
//    }
//};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size(), i = 0, nums_max = INT_MIN;
        vector<int> result(n, -1);
        stack<int> lower;
        while (i < n) {
            if (nums[i] > nums_max)
                nums_max = nums[i];
            if (!lower.empty() && nums[i] > nums[lower.top()])
                while (!lower.empty() && nums[i] > nums[lower.top()]) {
                    result[lower.top()] = nums[i];
                    lower.pop();
                }
            lower.push(i++);
        }
        i = 0;
        while (i < n) {
            while (!lower.empty() && nums[i] > nums[lower.top()]) {
                result[lower.top()] = nums[i];
                lower.pop();
            }
            if (nums[lower.top()] == nums_max)
                break;
            i++;
        }
        return result;
    }
};


int main() {
    Solution solution;
    int num[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    vector<int> nums(num, num + sizeof(num) / sizeof(int));
    for (int res: solution.nextGreaterElements(nums))
        cout << res << "\t";
    return 0;
}