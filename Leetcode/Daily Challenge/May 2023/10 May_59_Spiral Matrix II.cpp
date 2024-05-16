class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int l=0,r=n-1,top=0,btm=n-1,i,j,val=1;
        while(l<=r && top<=btm)
        {
            i=top; j=l;
            while(j<=r)
            mat[i][j++]=val++;
            top++;
            i=top; j=r;
            while(i<=btm)
            mat[i++][j]=val++;
            r--;
            i=btm; j=r;
            while(j>=l)
            mat[i][j--]=val++;
            btm--;
            i=btm; j=l;
            while(i>=top)
            mat[i--][j]=val++;
            l++;
        }
        return mat;
    }
};
