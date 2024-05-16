//Longest Substring Without Repeating
//O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int mx=0,l=0,r=0;
        while(r<s.length())
        {
            if(mp[s[r]]>0 && mp[s[r]]>=l)
            {
                mx=max(mx,(r-l));
                l=mp[s[r]];
            }
            mp[s[r]]=r+1;
            r++;
        }
        mx=max(mx,(r-l));

        return mx;
    }
};
//O(2n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int mx=0;
      unordered_map<char,int> mp;
      int l=0, r=0;
      while(r<s.length())
      {
    	while(mp[s[r]]>0)
        {
            mp[s[l]]--;
            l++;
        }
        mp[s[r]]++;
        mx=max(mx,(r-l+1));
      	r++;
      }
      return mx;
    }
};
