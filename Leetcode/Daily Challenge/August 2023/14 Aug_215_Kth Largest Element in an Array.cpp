//Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            pq.pop();
        }
        return pq.top();
    }
};
//Quick Select
class Solution {
public:
    int find(vector<int> &nums, int l, int &p)
    {
        for(int i=l;i<p;i++)
        {
            if(nums[p]<nums[i])
            {
                swap(nums[i],nums[l]);
                l++;
            }
        }
        swap(nums[l],nums[p]);
        return l;
    }
    int divide(int l, int r, vector<int> &nums, int &k)
    {
        if(l>=r)
        {
            if(l==r && l+1==k)
            return nums[l];
            else
            return 0;
        }
        int pivot=find(nums,l,r);
        if(pivot+1==k)
        return nums[pivot];

        if(k<=pivot+1)
        return divide(l,pivot-1,nums,k);
        else
        return divide(pivot+1,r,nums,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return divide(0,nums.size()-1,nums,k);
    }
};
