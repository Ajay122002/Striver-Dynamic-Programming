//Memoization
long long int solve(int start,int ind, vector<int>&nums,vector<long long int>&dp){
    if(ind == start) return nums[ind];
    if(ind < start) return 0;
    if(dp[ind]!=-1) return dp[ind];
    long long int pick = nums[ind]+solve(start,ind-2,nums,dp);
    long long int not_pick = solve(start, ind-1,nums,dp);
    dp[ind]=max(pick,not_pick);
    return dp[ind];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<long long int>dp1(n,-1);
    vector<long long int>dp2(n,-1);
    solve(0,n-2,valueInHouse,dp1);
    solve(1,n-1,valueInHouse,dp2);
    return max(dp1[n-2],dp2[n-1]);
}