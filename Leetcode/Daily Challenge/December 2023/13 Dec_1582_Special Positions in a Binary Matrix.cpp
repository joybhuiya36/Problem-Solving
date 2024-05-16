class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int cnt=0;
        vector<int> r(m,0);
        vector<int> c(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    r[i]++; c[j]++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    if(r[i]==1 && c[j]==1)
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
