class Solution {
public:
vector<int> dp;
    int func(int i, vector<int>& days, vector<int>& costs)
    {
        if(i>=days.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int op1=costs[0]+func(i+1,days,costs);
        int k=i;
        if(days[i]+7<=days.back())
        while(k<days.size())
        {
            if(days[k]>=days[i]+7)
            break;
            k++;
        }
        else k=days.size();
        int op2=costs[1]+func(k,days,costs);
        if(days[i]+30<=days.back())
        while(k<days.size())
        {
            if(days[k]>=days[i]+30)
            break;
            k++;
        }
        else k=days.size();
        int op3=costs[2]+func(k,days,costs);
        return dp[i]=min(op1,min(op2,op3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(),-1);
        return func(0,days,costs);
    }
};
