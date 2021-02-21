#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool comp(const vector<int> &u, const vector<int> &v) {
        return u[1] < v[1];
    }

    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.empty())
            return 0;
        sort(points.begin(), points.end(), comp);
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int> &balloon: points) {
            if (balloon[0] > pos) {
                pos = balloon[1];
                ++ans;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int point[4][2] = {{1, 2},
                       {3, 4},
                       {5, 6},
                       {7, 8}};
    vector<vector<int> > points;
    points.emplace_back(point[0], point[0] + 2);
    points.emplace_back(point[1], point[1] + 2);
    points.emplace_back(point[2], point[2] + 2);
    points.emplace_back(point[3], point[3] + 2);
    cout << solution.findMinArrowShots(points);
    return 0;
}