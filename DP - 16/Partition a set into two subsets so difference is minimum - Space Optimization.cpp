// Space Optimization
#include <bits/stdc++.h>

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum == 0) return 0;
    if (n == 1) return arr[0];

    vector<int>dp(sum + 1, INT_MAX);
    vector<int>curr(sum + 1, INT_MAX);
    for (int i = 0; i < sum; i++) {
        dp[i] = abs(i - (sum - i));
    }
    dp[sum] = INT_MAX;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            int not_pick = dp[j];
            int pick = INT_MAX;
            if (arr[i] <= j)
                pick = dp[j - arr[i]];
            curr[j] = min(pick, not_pick);
        }
        dp = curr;
    }

    return dp[sum];
}