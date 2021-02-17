#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    queue<int> q;
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        int res = 0, p = 0;
        for (int i = 0; i < n; ++i) {
            if (i == q.front()){
                q.pop();
                p = !p;
            }
            if (A[i] == p){
                if (i + K > n)
                    return -1;
                ++res;
                q.push(i + K);
                p = !p;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    int num[] = {0, 0, 0, 1, 0, 1, 1, 0};
    vector<int> row(num, num + sizeof(num) / sizeof(int));
    cout << solution.minKBitFlips(row, 3);
    return 0;
}
