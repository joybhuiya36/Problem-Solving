//[-1,0,1,2,-1,-4]
//[0,1,1]
//[0,0,0]
//[-1,0,1,2,2,-1,-1,-4]
//[1,2,-2,1,-1]
//[-2,0,1,1,2]
class Solution {
public:
    int b_search(int l, int r, int key, vector<int>& nums)
    {
        while(l<=r)
        {
            int mid=((r-l)/2)+l;
            if(nums[mid]==key)
            return mid;
            else if(nums[mid]>key)
            r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<string,int> mp;
        int left=0, right=nums.size()-1,idx,key;
        sort(nums.begin(),nums.end());
        while(right-left>1)
        {
            key=(nums[left]+nums[right])*(-1);
            idx=b_search(left+1,right-1,key,nums);
            if(idx!=-1)
            {
                
                string s=to_string(nums[left])+to_string(nums[idx])+to_string(nums[right]);
                if(!mp.count(s))
                {
                    ans.push_back({nums[left],nums[idx],nums[right]});
                    mp[s]++;
                }
                if(right-idx<idx-left)
                left++;
                else if(right-idx>idx-left)
                right--;
                else
                {
                    left++; right--;
                }
            }
            else
            {
                if(key<=nums[left])
                right--;
                else if(key>=nums[right])
                left++;
                else
                {
                    left++; right--;
                }
            }
        }
        return ans;
    }
};
