//Matrix as a linear array binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int l=0, mid, r=m*n-1;
        while(l<=r)
        {
            mid=((r-l)/2)+l;
            if(matrix[mid/n][mid%n]==target)
            return true;
            else if(matrix[mid/n][mid%n]>target)
            r=mid-1;
            else l=mid+1;
        }
        return false;
    }
};
//Row by row binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        for(int i=0;i<m.size();i++)
        {
            int l=0, r=m[0].size()-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(m[i][mid]==target)
                return true;
                else if(m[i][mid]>target)
                r=mid-1;
                else
                l=mid+1;
            }
            if(r==-1)
            return false;
        }
        return false;
    }
};
