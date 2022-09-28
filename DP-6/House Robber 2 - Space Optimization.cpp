// Space Optimization
long long int houseRobber(vector<int>& nums)
{
    int n = nums.size();
    long long int curr1 = 0, pre1 = 0, pre2 = 0;
    long long int curr2 = 0, prev1 = nums[0], prev2 = 0;
    for(int i=1;i<n;i++){
        curr1 = max(nums[i]+pre2,pre1);
        pre2 = pre1;
        pre1 = curr1;
    }
    for(int i=1;i<n-1;i++){
        curr2 = max(nums[i]+prev2,prev1);
        prev2 = prev1;
        prev1 = curr2;
    }
    long long int ans1 = max(curr1,pre1);
    long long int ans2 = max(curr2,prev1);
    return max(ans1,ans2);
}