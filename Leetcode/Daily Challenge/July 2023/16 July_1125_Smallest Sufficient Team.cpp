class Solution {
public:
int t_mask,m,n;
vector<int> ans;
    void team(int idx, int mask, int p[], vector<int> &v, vector<vector<int>> &dp)
    {
        if(mask==t_mask)
        {
            if(ans.size()==0 || v.size()<ans.size())
            ans=v;
            return;
        }
        if(idx==m)
        {
            if(mask==t_mask)
            {
                if(ans.size()==0 || v.size()<ans.size())
                ans=v;
            }
            return;
        }
        if(ans.size()!=0 && v.size()>=ans.size())
        return;
        if(dp[idx][mask]!=-1)
        {
            if(dp[idx][mask]<=v.size())
            return;
        }
        team(idx+1,mask,p,v,dp);   //not_taken
        if(p[idx]==0) return;
        v.push_back(idx);
        team(idx+1,mask|p[idx],p,v,dp);    //taken
        v.pop_back();

        if(v.size()!=0)
        dp[idx][mask]=v.size();
    }
    vector<int> smallestSufficientTeam(vector<string>& skill, vector<vector<string>>& people) {
        n=skill.size(), m=people.size();
        t_mask=pow(2,n)-1;

        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        mp[skill[i]]=i;

        int cur;
        int peoplemask[m];
        for(int i=0;i<m;i++)
        {
            cur=0;
            for(auto &j:people[i])
            {
                cur|=(1<<mp[j]);
            }
            peoplemask[i]=cur;
        }
        vector<int> v;
        vector<vector<int>> dp(m,vector<int>(t_mask+1,-1));
        team(0,0,peoplemask,v,dp);
        return ans;
    }
};
