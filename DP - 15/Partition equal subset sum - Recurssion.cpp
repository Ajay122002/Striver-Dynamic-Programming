// Recurssion
bool recurr(vector<int>&arr, int n, int target, int i) {
    if (i == 0) {
        if (target == arr[i])
            return true;
        return false;
    }

    bool not_pick = recurr(arr, n, target, i - 1);
    bool pick = false;
    if (target >= arr[i])
        pick = recurr(arr, n, target - arr[i], i - 1);
    return pick | not_pick;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    if (sum % 2 == 1) return false;

    return recurr(arr, n, sum / 2, n - 1);
}
