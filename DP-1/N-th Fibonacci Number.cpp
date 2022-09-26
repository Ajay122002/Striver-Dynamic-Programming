#include <bits/stdc++.h> 
// Recurssion
int mod = 1000000007;

int recurr(int n){
    if(n == 0)
        return 0;
    if(n==1) return 1;
    return (recurr(n-1)+recurr(n-2))%mod;
}

// Memoization
int solve(int n, vector<int>&dp){
    if(n == 1) return dp[n]=1;
    if(n == 0) return dp[n]=0;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = (solve(n-1,dp)+solve(n-2,dp))%mod;
}

int fibonacciNumber(int n){
    //return recurr(n)%mod; --> Recurssion
    
    // Memoization
    vector<int>dp(n+1,-1);
    solve(n,dp);
    return dp[n]%mod;
    
    //Tabulation
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i] = (dp[i-1]+dp[i-2])%mod;
    return dp[n];
    
    // Space Optimization
     int curr = 1,prev = 1, prev2=0;
    for(int i=2;i<=n;i++){
        curr = (prev+prev2)%mod;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}