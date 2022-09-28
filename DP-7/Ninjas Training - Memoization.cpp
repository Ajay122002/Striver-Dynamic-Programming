// Memoization
int solve(vector<vector<int>>&dp, int last, vector<vector<int>>&points, int ind){ 
    if(ind == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi,points[0][i]);
        }
        return maxi;
    }
    if(dp[ind][last]!=-1) return dp[ind][last];
    int ans = 0;
    for(int i=0;i<3;i++){
        int curr_points = 0;
        if(i!=last)
            curr_points = points[ind][i] + solve(dp,i,points,ind-1);
        ans = max(ans, curr_points);
    }
    dp[ind][last] = ans;
    return dp[ind][last];
}

int ninjaTraining(int n, vector<vector<int>>&points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    solve(dp,3,points,n-1);
    return dp[n-1][3];
}