//Bit Manipulation (XOR)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums[0];
        int loop=nums.size();
        for(int i=1;i<loop;i++)
        n^=nums[i];
        return n;
    }
};
