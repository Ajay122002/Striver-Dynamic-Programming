// Recurssion
long long int solve(int start,int ind, vector<int>&nums){
    if(ind == start) return nums[ind];
    if(ind < start) return 0;
    long long int pick = nums[ind]+solve(start,ind-2,nums);
    long long int not_pick = solve(start, ind-1,nums);
    return max(pick,not_pick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
     return max(solve(0,n-2,valueInHouse),solve(1,n-1,valueInHouse));
}