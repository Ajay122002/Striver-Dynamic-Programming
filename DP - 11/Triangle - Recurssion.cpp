// recurssion TLE
int solve(vector<vector<int>>&triangle, int i, int j, int n){
    if(i == n-1)
        return triangle[i][j];
    int down = triangle[i][j] + solve(triangle,i+1,j,n);
    int dia = triangle[i][j]+solve(triangle,i+1,j+1,n);
    return min(down ,dia);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    solve(triangle,0,0,n);
}