// Tabulation
long long int houseRobber(vector<int>& nums)
{
    int n = nums.size();
    if(n==1) return nums[0];
    vector<long long int>dp1(n,-1);
    vector<long long int>dp2(n,-1);
    dp1[0] = nums[0];
    dp2[0] = 0;
    
    for(int i=1;i<n-1;i++){
        dp1[i] = max(nums[i]+((i-2>=0)?dp1[i-2]:0),dp1[i-1]);
    }
    
    for(int i=1;i<n;i++){
        dp2[i] = max(nums[i]+((i-2>=0)?dp2[i-2]:0),dp2[i-1]);
    }
    
    return max(dp1[n-2],dp2[n-1]);
}