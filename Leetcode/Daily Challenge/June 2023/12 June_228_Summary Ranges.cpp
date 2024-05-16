class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> str;
        int n=nums.size(),j;
        string s="";
        for(int i=0;i<n;i++)
        {
            s=to_string(nums[i]);
            j=i;
            while(i+1<n && nums[i]+1==nums[i+1])
            i++;
            if(i!=j)
            s+="->"+to_string(nums[i]);
            str.emplace_back(s);
        }
        return str;
    }
};
