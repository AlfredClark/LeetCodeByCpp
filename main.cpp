#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        for (int i = 0; i <= num; ++i)
            result[i] = bitset<64>(i).count();
        return result;
    }
};

int main() {
    Solution solution;
    for (int num:solution.countBits(100))
        cout << num << "\t";
    return 0;
}