// Memoization
int mod=1000000007;  
int solve(int n,int m, vector<vector<int>>&mat, vector<vector<int>>&dp){
    if(n==0 && m==0)
        return dp[n][m]=1;
    if(n<0 || m<0 || mat[n][m] == -1)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    
    int left = solve(n-1,m,mat,dp)%mod;
    int right = solve(n,m-1,mat,dp)%mod;
    
    return dp[n][m]=(left+right)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    solve(n-1,m-1,mat,dp);
    return dp[n-1][m-1]%mod;
}