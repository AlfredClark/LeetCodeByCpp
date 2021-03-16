#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int floor = (n + 1) / 2, num = 1;
        for (int f = 0; f < floor; ++f) {
            int limit = n - f - 1;
            for (int i = f; i < limit; ++i)
                ret[f][i] = num++;
            for (int i = f; i < limit; ++i)
                ret[i][limit] = num++;
            for (int i = limit; i > f; --i)
                ret[limit][i] = num++;
            for (int i = limit; i > f; --i)
                ret[i][f] = num++;
        }
        if (num == n * n)
            ret[floor - 1][floor - 1] = num;
        return ret;
    }
};

int main() {
    Solution solution;
    int n = 7;
    for (const auto &line: solution.generateMatrix(n)) {
        for (int num: line)
            cout << num << "\t";
        cout << endl;
    }
    return 0;
}

