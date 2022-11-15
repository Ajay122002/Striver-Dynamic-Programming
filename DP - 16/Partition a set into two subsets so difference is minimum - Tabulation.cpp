// Tabulation
#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum == 0) return 0;
    if (n == 1) return arr[0];
    vector<vector<int>>dp(n, vector<int>(sum + 1, INT_MAX));
    for (int i = 0; i < sum; i++) {
        dp[0][i] = abs(i - (sum - i));
    }
    dp[0][sum] = INT_MAX;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            int not_pick = dp[i - 1][j];
            int pick = INT_MAX;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = min(pick, not_pick);
        }
    }

    return dp[n - 1][sum];
}
