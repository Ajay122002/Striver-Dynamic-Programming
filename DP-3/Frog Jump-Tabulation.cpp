//Tabulation
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &h)
{
    vector<int>dp(n);
    dp[0] = 0;
    if(n==1)
        return 0;
    dp[1] = abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);
    }
    return dp[n-1];
}