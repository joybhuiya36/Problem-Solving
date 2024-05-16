class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        vector<int>v(n);//resutl vector
        int k=n-1;//start traversing for the end of v till 0   
        
        while(low<=high){
            if(abs(nums[low]) > abs(nums[high])){
                v[k--]=nums[low] * nums[low];
                low++;
            }else{
                v[k--]=nums[high] * nums[high];
                high--;
            }
        }
        return v;
    }
};
//or
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v;
        int i=-1,j;
        for(int k=0;k<nums.size();k++)
        {
            if(nums[k]<0)
            i=k;
            else break;
        }
        j=i+1;
        while(i>=0 && j<nums.size())
        {
            if(abs(nums[i])<=nums[j])
            {
                v.push_back(nums[i]*nums[i]);
                i--;
            }
            else
            {
                v.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        while(i>=0)
        {
            v.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<nums.size())
        {
            v.push_back(nums[j]*nums[j]);
            j++;
        }
        return v;
    }
};
