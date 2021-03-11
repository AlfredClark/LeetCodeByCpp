#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    static void nums_opt(vector<int> &nums, char opt, int num) {
        switch (opt) {
            case '+':
                nums.push_back(num);
                break;
            case '-':
                nums.push_back(-num);
                break;
            case '*':
                nums.back() *= num;
                break;
            default:
                nums.back() /= num;
        }
    }

public:
    int calculate(string s) {
        vector<int> nums;
        int num = 0, n = s.size();
        char last_opt = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + int(c - '0');
            } else if (c != ' ') {
                nums_opt(nums, last_opt, num);
                last_opt = c;
                num = 0;
            }
            if (i == n - 1)
                nums_opt(nums, last_opt, num);
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main() {
    Solution solution;
    cout << solution.calculate(" 3/2") << endl;
    return 0;
}

