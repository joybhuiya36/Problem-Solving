//preSum matching
class Solution {
public:
	bool checker(int i, int j, vector<vector<int>> &g, int &n)
    {
        for(int k=0; k<n; k++)
        {
            if(g[i][k]!=g[k][j])
            return false;
        }
        return true;
    }
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size(),count=0;
        int row[n],col[n];
        for(int i=0;i<n;i++)
        {
            row[i]=col[i]=0;
            for(int j=0;j<n;j++)
            {
                row[i]+=grid[i][j];
                col[i]+=grid[j][i];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]==col[j] && checker(i,j,grid,n))
                count++;
            }
        }
        return count;
    }
};
//Row Mapping
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> mp;
        vector<int> col(n);
        int count=0;
        for(int i=0;i<n;i++)
        mp[grid[i]]++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            col[j]=grid[j][i];
            count+=mp[col];
        }
        return count;
    }
};
