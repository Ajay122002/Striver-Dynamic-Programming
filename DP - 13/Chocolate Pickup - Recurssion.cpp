// Recurssion - TLE
#include <bits/stdc++.h>

int recurssion(int i, int j1, int j2, vector<vector<int>>&grid, int n, int m) {
    //First write out of bound condition
    if (j1 < 0 || j1 > m - 1 || j2 < 0 || j2 > m - 1) return -1e9;

    //Base condition
    if (i == n - 1) {
        if (j1 == j2) return grid[i][j1];
        else return (grid[i][j1] + grid[i][j2]);
    }
    // Traversing through all the paths that alice and bob visit
    int maxi = 0;
    for (int l = -1; l <= 1; l++) {
        for (int k = -1; k <= 1; k++) {
            if (j1 == j2) {
                maxi = max(maxi, grid[i][j1] + recurssion(i + 1, j1 + l, j2 + k, grid, n, m));
            } else {
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + recurssion(i + 1, j1 + l, j2 + k, grid, n, m));
            }
        }
    }
    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return recurssion(0, 0, c - 1, grid, r, c);
}