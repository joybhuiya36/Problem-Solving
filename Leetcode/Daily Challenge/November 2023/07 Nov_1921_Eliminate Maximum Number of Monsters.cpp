class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double> a(n);
        for(int i=0;i<n;i++)
        a[i]=1.0*dist[i]/speed[i];
        sort(a.begin(),a.end());
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]-i>0)
            ans++;
            else break;
        }
        return ans;
    }
};
