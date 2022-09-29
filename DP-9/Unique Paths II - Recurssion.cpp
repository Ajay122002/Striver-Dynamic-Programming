// Recurssion TLE
int mod=1000000007;  
int solve(int n,int m, vector<vector<int>>&mat){
    if(n==0 && m==0)
        return 1;
    if(n<0 || m<0 || mat[n][m] == -1)
        return 0;
    
    int left = solve(n-1,m,mat);
    int right = solve(n,m-1,mat);
    
    return left+right;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return solve(n-1,m-1,mat);
}