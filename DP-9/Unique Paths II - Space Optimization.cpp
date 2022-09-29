// Space Optimization
#include<bits/stdc++.h>
int mod=1000000007;  

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int>pre(m,-1);
    for(int i=0;i<n;i++){
        vector<int>temp(m);
        for(int j=0;j<m;j++){
            if(mat[i][j] == -1){
                temp[j] = 0;
            }
            else if(i==0 && j==0){
                temp[j] = 1;
            }else{
                int up = 0, left= 0;
                if(i>0) up = pre[j];
                if(j>0) left = temp[j-1];
                temp[j] = (up+left)%mod;
            }
        }
        pre=temp;
    }
    return pre[m-1]%mod;
}