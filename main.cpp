#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            sums.resize(m + 1, vector<int>(n + 1));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }
};

int main() {
    int m[5][5] = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
    vector<vector<int>> matrix;
    for (auto &i : m)
        matrix.emplace_back(i, i + 5);
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(1, 1, 2, 2);
    return 0;
}