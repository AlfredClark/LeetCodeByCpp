#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static int clumsy(int N) {
        if (N == 0)
            return 0;
        int ans = 0, tmp = N--;
        for (int i = 0; N; ++i) {
            switch (i % 4) {
                case 0:
                    tmp *= N--;
                    break;
                case 1:
                    tmp /= N--;
                    ans += tmp;
                    tmp = 0;
                    break;
                case 2:
                    ans += N--;
                    break;
                default:
                    tmp = -N--;
                    break;
            }
        }
        return ans + tmp;
    }
};

int main() {
    Solution solution;
    cout << solution.clumsy(10) << endl;
    return 0;
}

