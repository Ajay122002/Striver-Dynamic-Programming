// Memoization
int solve(vector<vector<int>>&triangle, int i, int j, int n, vector<vector<int>>&dp){
    if(i == n-1)
        return triangle[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    int down = triangle[i][j] + solve(triangle,i+1,j,n,dp);
    int dia = triangle[i][j]+solve(triangle,i+1,j+1,n,dp);
    return dp[i][j] = min(down ,dia);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return solve(triangle,0,0,n,dp);
}