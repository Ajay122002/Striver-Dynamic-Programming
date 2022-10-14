// Space Optimization
// 1d -> two variables
// 2d -> 1d dp
// *** 3d will space optimized to 2d dp

#include <bits/stdc++.h>

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // declaring 2D vector of size M*M;
    vector<vector<int>>front(m, vector<int>(m, 0));
    vector<vector<int>>curr(m, vector<int>(m, 0));
    //Base case
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) {
                front[j1][j2] = grid[n - 1][j1];
            } else {
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = -1e9;
                for (int l = -1; l <= 1; l++) {
                    for (int k = -1; k <= 1; k++) {
                        if (j1 == j2) {
                            if (j1 + l >= 0 && j1 + l < m && j2 + k >= 0 && j2 + k < m) {
                                maxi = max(maxi, grid[i][j1] + front[j1 + l][j2 + k]);
                            }
                        } else {
                            if (j1 + l >= 0 && j1 + l < m && j2 + k >= 0 && j2 + k < m) {
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + front[j1 + l][j2 + k]);
                            }
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m - 1];
}
