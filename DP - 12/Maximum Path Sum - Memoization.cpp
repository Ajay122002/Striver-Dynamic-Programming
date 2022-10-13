// Memoization
#include<bits/stdc++.h>
int recurssion( int i, int j, vector<vector<int>>&matrix, int n, int m, vector<vector<int>>&dp){
    if(j<0 || j>m-1) return -1e9;
    if(i == 0) return matrix[0][j];
    if(dp[i][j]!=-1) return dp[i][j];
    
    int s = matrix[i][j]+recurssion(i-1,j,matrix,n,m,dp);
    int ld = matrix[i][j]+recurssion(i-1,j-1,matrix,n,m,dp);
    int rd = matrix[i][j]+recurssion(i-1,j+1,matrix,n,m,dp);
    return dp[i][j] = max(s,max(ld,rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
 
    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    int ans = INT_MIN;
    for(int i=0;i<m;i++){
        ans = max(ans,recurssion(n-1,i,matrix,n,m,dp));
    }
    return ans;
}