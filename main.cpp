#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(const string &s, int left, int right, int k, vector<int> &count) {
        count.clear();
        for (int i = left; i <= right; ++i)
            count[s[i] - 'a']++;
        char split = 0;
        for (int i = 0; i < 26; ++i)
            if (count[i] > 0 && count[i] < k) {
                split = 'a' + i;
                break;
            }
        if (split == 0)
            return right - left + 1;
        int result = 0, i = left;
        while (i <= right) {
            while (i <= right && s[i] == split)
                i++;
            if (i > right)
                break;
            int start = i;
            while (i <= right && s[i] != split)
                i++;
            result = max(result, dfs(s, start, i - 1, k, count));
        }
        return result;
    }

    int longestSubstring(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);
        return dfs(s, 0, n - 1, k, count);
    }
};

int main() {
    Solution solution;
    cout << solution.longestSubstring("aacabcbacbdcsasdaxczxcac", 3);
    return 0;
}