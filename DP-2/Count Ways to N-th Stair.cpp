#include <bits/stdc++.h> 
int mod = 1000000007;

// Recurssion
int recurr(int n){
    if(n == 0 || n==1)
        return 1;
    return recurr(n-1)+recurr(n-2);
}

//Memoization using 1d-vector
int solve(int n,vector<int>&dp){
    if(n == 0 || n==1)
        return dp[n]=1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=(solve(n-1,dp)+solve(n-2,dp))%mod;
}


//Tabulation
int countDistinctWays(int stairs) {
    //return recurr(stairs); --> Recurssion
    vector<int>dp(stairs+1,-1);
    //solve(stairs,dp); -- > Memoization
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=stairs;i++){
        dp[i] = (dp[i-1]+dp[i-2])%mod;
    }
    return dp[stairs]%mod;
}

// Space Optimization
int countDistinctWays(int stairs) {
    int curr = 1, prev= 1, prev2=0;
    for(int i=1;i<=stairs;i++){
        curr = (prev+prev2)%mod;
        prev2 = prev;
        prev = curr;
    }
    return curr%mod;
}