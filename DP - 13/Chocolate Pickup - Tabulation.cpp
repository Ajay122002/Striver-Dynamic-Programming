// Tabulation
#include <bits/stdc++.h>

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // declaring 3D vector of size N*M*M;
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    //Base case
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) {
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            } else {
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
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
                                maxi = max(maxi, grid[i][j1] + dp[i + 1][j1 + l][j2 + k]);
                            }
                        } else {
                            if (j1 + l >= 0 && j1 + l < m && j2 + k >= 0 && j2 + k < m) {
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + l][j2 + k]);
                            }
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
