class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector< vector<int> >v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                v[i].push_back(1);
                else
                v[i].push_back(v[i-1][j]+v[i-1][j-1]);
            }
        }
        return v;
    }
};
