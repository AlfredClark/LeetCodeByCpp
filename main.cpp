#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int count = 0, gi = 0, si = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (gi < g.size() && si < s.size()) {
            if (s[si] >= g[gi]) {
                gi++;
                count++;
            }
            si++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    int g_num[] = {2, 5, 15, 9, 10, 9};
    int s_num[] = {8, 3, 6, 1, 20};
    vector<int> g(g_num, g_num + sizeof(g_num) / sizeof(int));
    vector<int> s(s_num, s_num + sizeof(s_num) / sizeof(int));
    cout << solution.findContentChildren(g, s);
    return 0;
}