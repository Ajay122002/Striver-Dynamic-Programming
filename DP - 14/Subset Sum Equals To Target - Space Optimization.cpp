// Space Optimization
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>dp(k + 1, 0);
    vector<bool>curr(k + 1, 0);
    // Base cases for tabulation
    dp[0] = true;
    dp[arr[0]] = true;

    // we will start from i = 1 because dp is already assinged with false by declaring dp as bool so no need to assign false.
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool not_take = dp[target];
            bool take = false;
            if (arr[ind] <= target)
                take = dp[target - arr[ind]];
            curr[target] = take | not_take;
        }
        dp = curr;
    }
    return dp[k];
}