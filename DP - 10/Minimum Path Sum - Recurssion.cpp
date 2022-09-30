// Recurssion - TLE
#include<bits/stdc++.h>
int solve(int m,int n,vector<vector<int>> &grid){
    if(m==0 && n==0)
        return grid[0][0];
    if(n<0 || m<0)
        return 1000000000;
    int left = grid[m][n]+solve(m-1,n,grid);
    int right = grid[m][n]+solve(m,n-1,grid);
    return min(left,right);
}
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    return solve(m-1,n-1,grid);
}