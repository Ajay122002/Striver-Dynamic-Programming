// Recurssion
int solve(int last, vector<vector<int>>&points, int ind){ 
    if(ind == 0){
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last)
                maxi = max(maxi,points[0][i]);
        }
        return maxi;
    }
    int ans = 0;
    for(int i=0;i<3;i++){
        int curr_points = 0;
        if(i!=last)
            curr_points = points[ind][i] + solve(i,points,ind-1);
        ans = max(ans, curr_points);
    }
    return ans;
}

int ninjaTraining(int n, vector<vector<int>>&points)
{
    return solve(3,points,n-1);
}