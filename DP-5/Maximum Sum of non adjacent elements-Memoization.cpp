// Memoization
int solve(int ind, vector<int>&nums, vector<int>&dp){
    if(ind == 0) return dp[ind] = nums[ind];
    if(ind<0) return dp[ind] = 0;
    if(dp[ind] != -1) return dp[ind];
    int pick = nums[ind]+solve(ind-2,nums,dp);
    int not_pick = 0+solve(ind-1,nums,dp);
    dp[ind] = max(pick,not_pick);
    return dp[ind];
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n+1,-1);
    solve(n-1,nums,dp);
    return dp[n-1];
}