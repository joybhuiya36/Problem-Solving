class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0,b=0,temp;
        for(int i=cost.size()-1;i>=0;i--)
        {
            temp=a;
            a=cost[i]+min(a,b);
            b=temp;
        }
        return min(a,b);
    }
};
