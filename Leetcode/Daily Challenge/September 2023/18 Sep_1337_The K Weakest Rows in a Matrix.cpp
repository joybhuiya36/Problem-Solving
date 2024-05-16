class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int m=mat.size(), n=mat[0].size(),c;
        for(int i=0;i<m;i++)
        {
            c=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1) c++;
                else break;
            }
            pq.push({c,i});
            if(pq.size()>k)
            pq.pop();
        }
        vector<int> v(k);
        for(int i=k-1;i>=0;i--)
        {
            v[i]=pq.top().second;
            pq.pop();
        }
        return v;
    }
};
