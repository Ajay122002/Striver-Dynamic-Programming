// Space Optimization
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 == 1)
        return false;
    vector<bool>dp(sum / 2 + 1, 0);
    vector<bool>curr(sum / 2 + 1, 0);

    dp[0] = true;
    dp[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            bool not_pick = dp[j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[j - arr[i]];
            curr[j] = pick | not_pick;
        }
        dp = curr;
    }
    return dp[sum / 2];
}