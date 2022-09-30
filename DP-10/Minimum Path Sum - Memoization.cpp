// Memoization
#include<bits/stdc++.h>
int solve(int m,int n,vector<vector<int>> &grid, vector<vector<int>>&dp){
    if(m==0 && n==0)
        return grid[0][0];
    if(n<0 || m<0)
        return 1000000000;
    if(dp[m][n]!=-1)
        return dp[m][n];
    int left = grid[m][n]+solve(m-1,n,grid,dp);
    int right = grid[m][n]+solve(m,n-1,grid,dp);
    return dp[m][n] = min(left,right);
}
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(m-1,n-1,grid,dp);
}