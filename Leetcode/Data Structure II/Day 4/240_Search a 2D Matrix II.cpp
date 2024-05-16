class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row= mat.size(), col= mat[0].size(), i=0, j=col-1;
        while(i<row && j>=0)
        {
            if(mat[i][j]==target)
            {
                mat.clear();
                return true;
            }
            else if (mat[i][j]<target)
            i++;
            else j--;
        }
        mat.clear();
        return false;
    }
};
//Binary_Search Approach
class Solution {
public:
    bool b_search(vector<int> &mat, int & key)
    {
        int l=0, r=mat.size();
        while(l<=r)
        {
            int mid=((r-l)/2)+l;
            if(mat[mid]==key)
            return true;
            else if(mat[mid]>key)
            r=mid-1;
            else l=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=0;
        for(;row<mat.size();row++)
        {
            if(target<=mat[row].back())
            break;
        }
        for(int i=row;i<mat.size();i++)
        {
            if(target<=mat[row].back())
            {
                if(b_search(mat[i],target))
                return true;
                else continue;
            }
            else return false;
        }
        return false;
    }
};
