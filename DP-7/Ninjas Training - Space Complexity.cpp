// Space Optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>pre(4,0);
    pre[0] = max(points[0][1],points[0][2]);
    pre[1] = max(points[0][2],points[0][0]);
    pre[2] = max(points[0][1],points[0][0]);
    pre[3] = max(points[0][0],max(points[0][2],points[0][1]));
    
    for(int day = 1;day<n;day++){
        vector<int>temp(4,0);
        for(int last = 0;last<4;last++){
            for(int task = 0; task<3;task++){
                if(task!=last){
                    temp[last] = max(temp[last],points[day][task]+pre[task]);
                }
            }
        }
        pre = temp;
    }
    return pre[3];
}