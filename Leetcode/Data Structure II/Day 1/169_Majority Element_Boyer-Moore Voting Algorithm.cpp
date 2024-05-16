//Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, ans;
        for(int &n:nums)
        {
            if(count==0)
            ans=n;
            if(ans==n)
            count++;
            else count--;
        }
        return ans;
    }
};
