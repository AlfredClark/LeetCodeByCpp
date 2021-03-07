#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string &s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];

        dfs(s, 0);
        return ret;
    }
};

int main() {
    Solution solution;
    string s = "aabaaccbda";
    for (const auto &res: solution.partition(s)) {
        for (const auto &r: res)
            cout << r << "\t";
        cout << endl;
    }
    return 0;
}
// [
// ["a","a","b","a","a","c","c","b","d","a"],
// ["a","a","b","a","a","cc","b","d","a"],
// ["a","a","b","aa","c","c","b","d","a"],
// ["a","a","b","aa","cc","b","d","a"],
// ["a","aba","a","c","c","b","d","a"],
// ["a","aba","a","cc","b","d","a"],
// ["aa","b","a","a","c","c","b","d","a"],
// ["aa","b","a","a","cc","b","d","a"],
// ["aa","b","aa","c","c","b","d","a"],
// ["aa","b","aa","cc","b","d","a"],
// ["aabaa","c","c","b","d","a"],
// ["aabaa","cc","b","d","a"]
// ]
