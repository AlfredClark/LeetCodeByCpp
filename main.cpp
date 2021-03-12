#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSerialization(const string &preorder) {
        int n = preorder.size();
        int root = 1, i = -1;
        while (++i < n) {
            root += isdigit(preorder[i]) ? 1 : -1;
            if (root < 1)
                return i == n - 1;
            while (i < n && preorder[i] != ',')
                i++;
        }
        cout << root << endl;
        return root == 0;
    }
};

int main() {
    Solution solution;
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << solution.isValidSerialization(s) << endl;
    return 0;
}

