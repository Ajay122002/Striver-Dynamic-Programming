// Recurssion - Own - TLE
#include <bits/stdc++.h>
bool recurssion(int n, int i, int sum, vector<int>&arr, int target) {
    if (i == n) {
        if (sum == target)
            return true;
        return false;
    }
    sum += arr[i];
    if (recurssion(n, i + 1, sum, arr, target) == true)
        return true;
    sum -= arr[i];
    if (recurssion(n, i + 1, sum, arr, target) == true)
        return true;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return recurssion(n, 0, 0, arr, k);
}