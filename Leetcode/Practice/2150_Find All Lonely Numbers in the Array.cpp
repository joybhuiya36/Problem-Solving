class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size(),mx=nums[0],flag=0;
        for(int i=1;i<n;i++)
        {
            if(mx!=nums[i])
            flag=1;
            mx=max(mx,nums[i]);
        }
        int arr[mx+1];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        arr[nums[i]]++;
        if(flag==0)
        {
            if(arr[mx]==1) return {mx};
            else return {};
        }
        vector<int> v;
        if(arr[0]==1 && arr[1]==0)
        v.push_back(0);
        for(int i=1;i<mx;i++)
        {
            if(arr[i]==1 && arr[i-1]==0 && arr[i+1]==0)
            v.push_back(i);
        }
        if(arr[mx]==1 && arr[mx-1]==0)
        v.push_back(mx);
        return v;
    }
};
