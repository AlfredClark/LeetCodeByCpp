#include <bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int maxEnvelopes(vector<vector<int>> &envelopes) {
//        if (envelopes.empty()) {
//            return 0;
//        }
//
//        int n = envelopes.size();
//        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2) {
//            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
//        });
//
//        vector<int> f(n, 1);
//        for (int i = 1; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (envelopes[j][1] < envelopes[i][1]) {
//                    f[i] = max(f[i], f[j] + 1);
//                }
//            }
//        }
//        return *max_element(f.begin(), f.end());
//    }
//};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        if (envelopes.empty())
            return 0;

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            if (int num = envelopes[i][1]; num > f.back()) {
                f.push_back(num);
            } else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }
};

int main() {
    Solution solution;
    int envelope[][2] = {
            {5, 4},
            {6, 4},
            {6, 7},
            {2, 3}
    };
    vector<vector<int>> envelopes;
    envelopes.reserve(4);
    for (int i = 0; i < 4; ++i)
        envelopes.emplace_back(envelope[i], envelope[i] + 2);
    cout << solution.maxEnvelopes(envelopes);
    return 0;
}