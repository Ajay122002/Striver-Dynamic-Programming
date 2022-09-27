// Recurssion
int solve(int ind, vector<int>&nums){
    if(ind == 0) return nums[ind];
    if(ind<0) return 0;
    int pick = nums[ind]+solve(ind-2,nums);
    int not_pick = 0+solve(ind-1,nums);
    return max(pick,not_pick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return solve(n-1,nums);
}