class NumMatrix {
public:
    vector<vector<int>> mat;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        mat.resize(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i+1][j+1]=matrix[i][j]+mat[i][j+1]+mat[i+1][j]-mat[i][j];
            }
        }
        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<mat[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return mat[r2+1][c2+1]-mat[r1][c2+1]-mat[r2+1][c1]+mat[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
