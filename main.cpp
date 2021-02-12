#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        long next = 1;
        for (int i = 0; i < rowIndex; ++i) {
            res[i] = next;
            next = (next * (rowIndex - i) / (i + 1));
        }
        return res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    Solution solution;
    for (int num: solution.getRow(30))
        cout << num << "\t";
    return 0;
}
