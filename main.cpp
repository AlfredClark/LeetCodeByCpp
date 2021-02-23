#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int res0 = 0, res1 = 0, left = 0, right = 0, grumpy_c = 0, n = customers.size();
        while (right < n) {
            if (right >= X && grumpy[left++])
                grumpy_c -= customers[left - 1];
            if (!grumpy[right++])
                res0 += customers[right - 1];
            else
                grumpy_c += customers[right - 1];
            res1 = max(res1, grumpy_c);
        }
        return res0 + res1;
    }
};

int main() {
    Solution solution;
    int customer[] = {1, 0, 1, 2, 1, 1, 7, 5, 1, 2, 3, 2, 1};
    int grump[] = {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
    vector<int> customers(customer, customer + sizeof(customer) / sizeof(int));
    vector<int> grumpy(grump, grump + sizeof(grump) / sizeof(int));
    cout << solution.maxSatisfied(customers, grumpy, 7);
    return 0;
}