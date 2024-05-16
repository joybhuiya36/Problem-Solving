class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int ans=0;
        vector<int> cur(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0) break;
                if(matrix[i][j]==1)
                {
                    matrix[i][j]=matrix[i-1][j]+1;
                }
            }
            cur=matrix[i];
            sort(cur.begin(),cur.end(),greater<int>());
            for(int j=0;j<n;j++)
            ans=max(ans,cur[j]*(j+1));
        }
        return ans;
    }
};
