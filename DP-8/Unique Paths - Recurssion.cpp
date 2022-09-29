// Recurssion
#include <bits/stdc++.h>
int solve(int m,int n){
    if(m == 0 && n==0)
        return 1;
    if(m<0 || n<0) 
        return 0;
    int left=solve(m-1,n);
    int right=solve(m,n-1);
    return left+right;
}
int uniquePaths(int m, int n) {
    return solve(m-1,n-1);
}