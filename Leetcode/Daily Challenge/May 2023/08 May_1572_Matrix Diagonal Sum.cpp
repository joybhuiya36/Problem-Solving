class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0,n=mat.size();
        for(int i=0;i<n/2;i++)
        sum+=mat[i][i]+mat[n-i-1][n-i-1]+mat[i][n-i-1]+mat[n-i-1][i];
        if(n%2==1)
        sum+=mat[(n/2)][(n/2)];
        return sum;
    }
};
