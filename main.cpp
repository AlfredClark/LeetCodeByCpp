#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};

int main() {
    Solution solution;
    cout << solution.hammingWeight(00101101) << endl;
    return 0;
}

