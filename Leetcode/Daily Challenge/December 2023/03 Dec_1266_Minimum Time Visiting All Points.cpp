class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int time=0;
        int a,b;
        for(int i=1;i<n;i++)
        {
            a=abs(points[i][0]-points[i-1][0]);
            b=abs(points[i][1]-points[i-1][1]);
            time+=max(a,b);
        }
        return time;
    }
};
