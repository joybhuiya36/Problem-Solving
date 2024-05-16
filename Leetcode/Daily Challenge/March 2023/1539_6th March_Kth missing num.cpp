//My Solution
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count=arr[0]-1,ind;
        if(count>=k)
        return k;
        for(int i=0,j=1;i<arr.size()-1;i++)
        {
            count+=arr[i+1]-arr[i]-1;
            if(count>=k)
            {
                ind=i;
                count-=arr[i+1]-arr[i]-1;
                break;
            }
        }
        int pos_num=arr[ind];
        pos_num+=k-count;
        return pos_num;
    }
};
//Binary Search Strategy
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size(), mid;
        while(lo < hi) {
            mid = (lo + hi) / 2;
            if(arr[mid] - mid - 1 < k) lo = mid + 1;
            else hi = mid;
        }
        return lo + k;
    }
};

