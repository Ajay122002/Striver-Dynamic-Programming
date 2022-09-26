// Recurssion Solution
#include<bits/stdc++.h>

int recurr(int n, vector<int>&h){
    if(n==0)
        return 0;
    int val1 = abs(h[n]-h[n-1])+recurr(n-1,h);
    int val2 = INT_MAX;
    if(n>1)
        val2 = abs(h[n]-h[n-2])+recurr(n-2,h);
    return min(val1,val2);
}
int frogJump(int n, vector<int> &h)
{
    return recurr(n-1,h);
}