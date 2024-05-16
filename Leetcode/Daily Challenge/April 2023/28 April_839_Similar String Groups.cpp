class Solution {
public:
int count;
    bool checker(string &a, string &b)
    {
        count=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            count++;
        }
        return count==0 || count==2;
    }
    void dfs(int idx, vector<bool> &visit, vector<vector<int>> &list)
    {
        visit[idx]=true;
        for(int i=0;i<list[idx].size();i++)
        {
            if(visit[list[idx][i]]==false)
            dfs(list[idx][i],visit,list);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>> list(n);
        vector<bool> visit(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(checker(strs[i],strs[j]))
                {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                count++;
                dfs(i,visit,list);
            }
        }
        return count;
    }
};
