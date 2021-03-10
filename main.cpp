#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(const string &s) {
        int ret = 0, base = 1, i = 0, n = s.size();
        stack<short> pos;
        pos.push(1);
        while (i < n) {
            char c = s[i];
            if (c == '+') {
                base = pos.top();
            } else if (c == '-') {
                base = -pos.top();
            } else if (c == '(') {
                pos.push(base);
            } else if (c == ')') {
                pos.pop();
            } else if (c != ' ') {
                pos.push(i);
                while (i < n && isdigit(s[i + 1]))
                    i++;
                ret += base * atoi(s.substr(pos.top(), i - pos.top() + 1).c_str());
                pos.pop();
            }
            i++;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string s = "(1+(4+5+2)-3)+(6+8)";
    cout << solution.calculate(s) << endl;
    return 0;
}

