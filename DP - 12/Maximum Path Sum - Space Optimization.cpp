// Space Optimization
#include<bits/stdc++.h>
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
 
    vector<int>dp(m,0);
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        vector<int>temp(m,0);
        for(int j=0;j<m;j++){
            if(i == 0) dp[j] = matrix[i][j];
            else{
                int s,ld,rd;
                (j-1>=0)?ld= dp[j-1]+matrix[i][j]:ld=-1e9;
                (j+1<=m-1)?rd= dp[j+1]+matrix[i][j]:rd=-1e9;
                s = dp[j]+matrix[i][j];
                temp[j] = max(s,max(ld,rd)); 
            }
        }
        if(i!=0)
        dp=temp;
    }
    for(int i=0;i<m;i++)    
        ans = max(ans,dp[i]);
    
    return ans;
}