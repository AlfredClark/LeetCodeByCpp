#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> rev(n);
        string str = rev.to_string();
        reverse(str.begin(), str.end());
        return bitset<32>(str).to_ulong();
    }
};

int main() {
    Solution solution;
    cout << solution.reverseBits(43261596) << endl;
    return 0;
}

