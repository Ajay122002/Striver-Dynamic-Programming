// Memoization
#include <bits/stdc++.h>
int recurr(int sum, vector<int>&arr, int i, int curr_sum, vector<vector<int>>&dp) {
    if (i == 0) {
        if (curr_sum != sum) {
            int sum_2 = sum - curr_sum;
            //cout<<curr_sum<<" "<<sum_2<<endl;
            return abs(sum_2 - curr_sum);
        }
        return INT_MAX;
    }
    if (dp[i][curr_sum] != -1) return dp[i][curr_sum];
    int pick = recurr(sum, arr, i - 1, curr_sum, dp);
    int not_pick = recurr(sum, arr, i - 1, curr_sum + arr[i], dp);
    return dp[i][curr_sum] = min(pick, not_pick);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum == 0) return 0;
    vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
    return recurr(sum, arr, n - 1, 0, dp);
}