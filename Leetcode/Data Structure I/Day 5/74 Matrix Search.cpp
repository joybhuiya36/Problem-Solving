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
//Binary Search on whole 2D matrix
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int n = matrix.size(), m = matrix[0].size();
//        int start = 0, end = n*m-1, mid;
//        while (start <= end)
//        {
//            mid = (end-start)/2 + start;
//            if (matrix[mid/m][mid%m] == target) return true;
//            else if (matrix[mid/m][mid%m] > target) end = mid-1;
//            else start = mid+1;
//        }
//        return false;
//    }
//};
