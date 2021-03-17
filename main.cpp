#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;
        vector<vector<long>> dp(m + 1, vector<long>(n + 1));
        for (int i = 0; i < m + 1; ++i)
            dp[i][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            char a = s.at(i);
            for (int j = n - 1; j >= 0; --j) {
                char b = t.at(j);
                if (a == b) {
                    dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution solution;
    string s = "rabbbit";
    string t = "rabbit";
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}

