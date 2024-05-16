class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector< vector<int> > arr(m, vector<int>(n,0));
        vector<int> v;
        int i=0,j=0,count=0;
        while(count<m*n)
        {
            
            while(i<m && j<n && !arr[i][j])
            {
                arr[i][j]=1;
                v.push_back(mat[i][j]);
                count++;
                j++;
            }
            j--;i++;
            while(i<m && !arr[i][j])
            {
                arr[i][j]=1;
                v.push_back(mat[i][j]);
                count++;
                i++;
            }
            i--;j--;
            while(j>=0 && !arr[i][j])
            {
                arr[i][j]=1;
                v.push_back(mat[i][j]);
                count++;
                j--;
            }
            j++;i--;
            while(i>=0 && j>=0 && !arr[i][j])
            {
                arr[i][j]=1;
                v.push_back(mat[i][j]);
                count++;
                i--;
            }
            i++;j++;
        }
        return v;
    }
};
