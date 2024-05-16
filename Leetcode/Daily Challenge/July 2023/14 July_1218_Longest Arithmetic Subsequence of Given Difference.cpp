class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n=arr.size(),cur,ans=1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            cur=(mp.count(arr[i]-diff)? mp[arr[i]-diff]:0)+1;
            ans=max(ans,cur);
            mp[arr[i]]=cur;
        }
        return ans;
    }
};
