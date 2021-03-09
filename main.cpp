#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    stack<unsigned short> recursive_stack;
    vector<vector<string>> results;
    vector<string> result;
    vector<unsigned short> status;

    static bool isPalindrome(const string &s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }

public:
    void dfs(const string &s, int start) {
        recursive_stack.push(start);
        while (!recursive_stack.empty()) {
            int begin = recursive_stack.top();
            int end = __builtin_ffs(status[begin]);
            result.push_back(s.substr(begin, end - begin));
            if (end >= s.length()){
                results.emplace_back(result.begin(), result.end());
                result.pop_back();
                status[begin] &= ~(1 << (end - 1));
            } else {
                recursive_stack.push(end);
            }
        }
    }

    vector<vector<string>> partition(const string &s) {
        int n = s.size();
        status.resize(n);
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                if (isPalindrome(s, i, j))
                    status[i] |= (1 << j);
        dfs(s, 0);
        return results;
    }
};

int main() {
    Solution solution;
    string s = "aabaaccbdbc";
    for (const auto &res: solution.partition(s)) {
        for (const auto &r: res)
            cout << r << "\t";
        cout << endl;
    }
    return 0;
}

