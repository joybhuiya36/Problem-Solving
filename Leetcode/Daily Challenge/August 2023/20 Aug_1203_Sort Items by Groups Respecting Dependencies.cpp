class Solution {
public:
	vector<int> tp(int ind[], vector<vector<int>> &adj, int n)
    {
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            q.push(i);
        }
        vector<int> v;
        int cur;
        while(!q.empty())
        {
            cur=q.front();
            q.pop();
            v.push_back(cur);
            for(int i=0;i<adj[cur].size();i++)
            {
                if(--ind[adj[cur][i]]==0)
                q.push(adj[cur][i]);
            }
        }
        if(v.size()==n)
        return v;
        else return {};
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++)
        {
            if(group[i]==-1)
            group[i]=m++;
        }
        int ind_item[n];
        int ind_grp[m];
        memset(ind_item,0,sizeof(ind_item));
        memset(ind_grp,0,sizeof(ind_grp));
        vector<vector<int>> adj(n);
        vector<vector<int>> adjj(m);
        for(int i=0;i<n;i++)
        {
            for(auto &pre:beforeItems[i])
            {
                adj[pre].push_back(i);
                ind_item[i]++;
                if(group[pre]!=group[i])
                {
                    adjj[group[pre]].push_back(group[i]);
                    ind_grp[group[i]]++;
                }
            }
        }
        vector<int> itm=tp(ind_item,adj,n);
        vector<int> grp=tp(ind_grp,adjj,m);
        if(itm.size()==0 || grp.size()==0)
        return {};
        vector<int> ans;
        vector<vector<int>> grpItm(m);
        for(int i=0;i<n;i++)
        {
            grpItm[group[itm[i]]].push_back(itm[i]);
        }
        for(int i=0;i<m;i++)
        {
            for(auto &j:grpItm[grp[i]])
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};
