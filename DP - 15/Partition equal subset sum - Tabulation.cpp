// tabulation
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 == 1)
        return false;
    vector<vector<bool>>dp(n, vector<bool>(sum / 2 + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum / 2; j++) {
            bool not_pick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = pick | not_pick;
        }
    }
    return dp[n - 1][sum / 2];
}