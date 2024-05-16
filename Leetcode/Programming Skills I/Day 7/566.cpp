class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rr=mat.size(), cc=mat[0].size();
        if(rr*cc!=r*c||(rr==r&&cc==c))
        return mat;
        vector<vector<int>> arr(r, vector<int>(c, 0));
        int m=0,n=0;
        for(int i=0;i<rr;i++)
        for(int j=0;j<cc;j++)
        {
            if(n==c)
            {m++;
            n=0;
            }
            arr[m][n]=mat[i][j];
            n++;
        }
        return arr;
    }
};

//vector<vector<int>> v(r, vector<int>(c,1));
