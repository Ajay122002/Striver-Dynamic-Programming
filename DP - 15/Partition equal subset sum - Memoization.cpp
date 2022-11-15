// Memoization
bool recurr(vector<int>&arr, int n, int target, int i, vector<vector<int>>&dp) {
    if (i == 0) {
        if (target == arr[i])
            return dp[i][target] = true;
        return dp[i][target] = false;
    }
    if (dp[i][target] != -1) return dp[i][target];
    bool not_pick = recurr(arr, n, target, i - 1, dp);
    bool pick = false;
    if (target >= arr[i])
        pick = recurr(arr, n, target - arr[i], i - 1, dp);
    return dp[i][target] = pick | not_pick;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 == 1)
        return false;
    vector<vector<int>>dp(n, vector<int>(sum / 2 + 1, -1));
    return recurr(arr, n, sum / 2, n - 1, dp);
}