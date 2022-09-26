// Space Optimization
#include<bits/stdc++.h>
int frogJump(int n, vector<int> &h)
{
    int a = 0;
    if(n==1)
        return 0;
    int b = abs(h[0]-h[1]);
    int c;
    for(int i=2;i<n;i++){
        c = min(abs(h[i]-h[i-1])+b,abs(h[i]-h[i-2])+a);
        a=b;
        b=c;
    }
    return min(b,c);
}