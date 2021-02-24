#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        int left, right, n = A.size();
        for (int i = 0; i < n; ++i)
            for (left = 0, right = A[i].size() - 1; left <= right; ++left, --right)
                if (A[i][left] == A[i][right])
                    A[i][left] = A[i][right] ^= 1;
        return A;
    }
};

int main() {
    Solution solution;

    return 0;
}