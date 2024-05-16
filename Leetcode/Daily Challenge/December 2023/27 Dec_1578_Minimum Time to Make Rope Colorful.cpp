class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length(), t=neededTime[0], ans=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i-1]==colors[i])
            {
                ans+=min(t,neededTime[i]);
                t=max(t,neededTime[i]);
            }
            else
            {
                t=neededTime[i];
            }
        }
        return ans;
    }
};
