// Space Optimization
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int curr,prev1=nums[0],prev2=0;
    curr =max(prev1,prev2);
    for(int i=1;i<n;i++){
        curr = max((nums[i]+prev2),prev1);
        prev2 = prev1;
        prev1 = curr; 
    }
    return max(prev1,curr);
}