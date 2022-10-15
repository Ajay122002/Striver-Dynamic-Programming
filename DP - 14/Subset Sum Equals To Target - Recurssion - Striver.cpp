// Recurssion - Striver TLE
#include <bits/stdc++.h>

bool recurssion(int ind, int target, vector<int>&arr) {
    if (target == 0) return true;
    if (ind == 0)
        if (arr[0] == target) return true;
        else return false;

    bool not_take = recurssion(ind - 1, target, arr);
    bool take = false;
    if (target >= arr[ind])
        take = recurssion(ind - 1, target - arr[ind], arr);
    if (take == true || not_take == true)
        return true;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return recurssion(n - 1, k, arr);
}