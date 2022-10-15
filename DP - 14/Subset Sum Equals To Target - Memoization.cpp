// Memoization
#include <bits/stdc++.h>

bool recurssion(int ind, int target, vector<int>&arr, vector<vector<int>>&dp) {
    if (target == 0) return true;
    if (ind == 0)
        if (arr[0] == target) return true;
        else return false;
    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool not_take = recurssion(ind - 1, target, arr, dp);
    bool take = false;
    if (target >= arr[ind])
        take = recurssion(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take | not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
    return recurssion(n - 1, k, arr, dp);
}