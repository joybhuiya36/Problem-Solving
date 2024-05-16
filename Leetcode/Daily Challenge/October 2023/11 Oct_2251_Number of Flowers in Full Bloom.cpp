class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m=flowers.size(), n=people.size();
        vector<int> start(m);
        vector<int> end(m);
        for(int i=0;i<m;i++)
        {
            start[i]=flowers[i][0];
            end[i]=flowers[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> ans(n);
        int fullBloom, finished;
        for(int i=0;i<n;i++)
        {
            fullBloom=upper_bound(start.begin(),start.end(),people[i])-start.begin();
            finished=lower_bound(end.begin(),end.end(),people[i])-end.begin();
            ans[i]=fullBloom-finished;
        }
        return ans;
    }
};
