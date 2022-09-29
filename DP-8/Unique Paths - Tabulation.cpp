// Tabulation
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(j-1 == 0 && i-1 == 0)
                dp[i][j] = 1+1;
            else if(j-1 == 0)
                dp[i][j] = dp[i-1][j]+1;
            else if(i-1==0)
                dp[i][j] = dp[i][j-1]+1;
            else
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
        }
    }
    if(m==1 || n==1)
        return 1;
    return dp[m-1][n-1];
}