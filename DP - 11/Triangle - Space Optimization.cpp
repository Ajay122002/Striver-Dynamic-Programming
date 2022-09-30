// Space Optimization
#include<bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<int>dp(n);
    for(int j=0;j<n;j++)
        dp[j] = triangle[n-1][j];
    for(int i=n-2;i>=0;i--){
        vector<int>temp(n);
        for(int j=i;j>=0;j--){
            int down = triangle[i][j]+dp[j];
            int dia = triangle[i][j]+dp[j+1];
            temp[j] = min(down, dia);
        }
        dp = temp;
    }
    return dp[0];
}