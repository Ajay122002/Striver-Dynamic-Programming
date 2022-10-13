// Tabulation
#include<bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
 
    vector<vector<int>>dp(n,vector<int>(m,-1));
    
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0) dp[i][j] = matrix[i][j];
            else{
                int s,ld,rd;
                (j-1>=0)?ld= dp[i-1][j-1]+matrix[i][j]:ld=-1e9;
                (j+1<=m-1)?rd= dp[i-1][j+1]+matrix[i][j]:rd=-1e9;
                s = dp[i-1][j]+matrix[i][j];
                dp[i][j] = max(s,max(ld,rd)); 
            }
        }
    }

    for(int i=0;i<m;i++)
        ans = max(ans,dp[n-1][i]);
    return ans;
}