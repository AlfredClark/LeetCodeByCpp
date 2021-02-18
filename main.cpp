#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int left = 0, right = 0;
        while (right < A.size()) {
            K -= !A[right++];
            K += K < 0 && !A[left++];
        }
        return right - left;
    }
};

int main() {
    Solution solution;
    int num[] = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    vector<int> row(num, num + sizeof(num) / sizeof(int));
    cout << solution.longestOnes(row, 3);
    return 0;
}