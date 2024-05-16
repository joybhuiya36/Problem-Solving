class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> st(nums.begin(),nums.end());
        vector<int> tmp(st.begin(),st.end());
        int m=tmp.size();
        int rslt=INT_MAX,l,r,j,inRange,outerRange;
        for(int i=0;i<m;i++)
        {
            l=tmp[i]; r=l+n-1;
            j=upper_bound(tmp.begin()+i,tmp.end(),r)-tmp.begin();
            inRange=j-i;
            outerRange=n-inRange;
            rslt=min(rslt,outerRange);
        }
        return rslt;
    }
};
//or
class Solution {
public:
int minOperations(vector<int>& nums) {
int N = nums.size(), i = 0, j = 0;
sort(begin(nums), end(nums));
nums.erase(unique(begin(nums), end(nums)), end(nums)); // only keep unique elements
for (int M = nums.size(); j < M; ++j) {
if (nums[i] + N <= nums[j]) ++i;
}
return N - j + i;
}
};
