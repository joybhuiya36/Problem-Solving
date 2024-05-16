class Solution {
public:
double total;
    double total_hours(int &speed, vector<int> &dist, int &n)
    {
        total=0.0;
        for(int i=0;i<n-1;i++)
        {
            total+=ceil(double(dist[i])/speed);
        }
        total+=double(dist[n-1])/speed;
        return total;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=0,r=1e7,mid,n=dist.size();
        while(l<=r)
        {
            mid=l+((r-l)/2);
            total=total_hours(mid,dist,n);
            if(total>hour)
            l=mid+1;
            else r=mid-1;
        }
        return l==1e7+1? -1: l;
    }
};
