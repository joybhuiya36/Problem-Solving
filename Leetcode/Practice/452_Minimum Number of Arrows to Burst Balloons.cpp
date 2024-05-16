class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size(),count=0;
        sort(points.begin(),points.end());
        vector<int> interval=points[0];
        for(int i=0;i<n;)
        {
            while(i<n && interval[0]<=points[i][0] && interval[1]>=points[i][0])
            {
                interval[0]=points[i][0];
                interval[1]=min(interval[1],points[i][1]);
                i++;
            }
            count++;
            if(i<n)
            interval=points[i];
        }
        return count;
    }
};
