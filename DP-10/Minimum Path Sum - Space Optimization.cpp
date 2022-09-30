// Space Optimization
#include<bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int>pre(n,0);
    vector<int>temp(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
                temp[j] = grid[0][0];
            else{
                int left = 1000000000,up = 1000000000;
                if(i>0) left = grid[i][j]+pre[j];
                if(j>0) up= grid[i][j]+temp[j-1];
                temp[j] = min(left,up);
            }
        }
        pre = temp;
    }
    return pre[n-1];
}