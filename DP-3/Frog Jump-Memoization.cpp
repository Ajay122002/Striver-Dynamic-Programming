//Memoization using 1-D Vector
#include<bits/stdc++.h> 
int solve(int i, vector<int>&h,vector<int>&dp){
    if(i==0) return 0;
    if(dp[i]!=-1)
        return dp[i];
    int val = abs(h[i]-h[i-1])+solve(i-1,h,dp);
    int val2=INT_MAX;
    if(i>1)
        val2 = abs(h[i]-h[i-2])+solve(i-2,h,dp);
    return dp[i] = min(val,val2);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    solve(n-1,heights,dp);
    return dp[n-1];
}