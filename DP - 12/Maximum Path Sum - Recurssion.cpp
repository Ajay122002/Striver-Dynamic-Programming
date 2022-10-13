// Recurssion TLE
#include<bits/stdc++.h>
int recurssion( int i, int j, vector<vector<int>>&matrix, int n, int m){
    if(j<0 || j>m-1) return -1e9;
    if(i == 0) return matrix[0][j];
    int s = matrix[i][j]+recurssion(i-1,j,matrix,n,m);
    int ld = matrix[i][j]+recurssion(i-1,j-1,matrix,n,m);
    int rd = matrix[i][j]+recurssion(i-1,j+1,matrix,n,m);
    return max(s,max(ld,rd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    for(int i=0;i<m;i++){
        ans = max(ans,recurssion(n-1,i,matrix,n,m));
    }
    return ans;
}